/*
 * This file is part of KotlinJNIQt.
 *
 * KotlinJNIQt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * KotlinJNIQt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with KotlinJNIQt.  If not, see <https://www.gnu.org/licenses/>.
 */

package com.keygenqt.kotlinqt.base

import org.json.*

class QtApp {
    companion object {

        lateinit var native: QtNative
        const val TYPE_SYSTEM_TRAY = "actionItemTray"

        fun emit(id: Int, params: String = "") {
            native.emit(id, params)
        }

        fun run(tray: (key: String) -> Unit) {

//            System.err.close()
//            System.setErr(System.out)

            native = QtNative()
            native.action(object : Listener {
                override fun invoke(json: String) {
                    val data = JSONObject(json)
                    when (data.getString("type")) {
                        TYPE_SYSTEM_TRAY -> {
                            tray.invoke(data.getString("key"))
                        }
                        "qDebug" -> {
                            println("println(${data.getString("data")})")
                        }
                    }
                }
            })
        }
    }
}