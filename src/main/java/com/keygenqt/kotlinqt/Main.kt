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

package com.keygenqt.kotlinqt

import com.keygenqt.kotlinqt.base.*
import com.keygenqt.kotlinqt.utils.*

fun main(args: Array<String>) {
    println("RUN")
    QtApp.run {
        when (it) {
            TRAY_SELECT -> {
                QtApp.emit(EMIT_NOTIFICATION_TRAY, "Test notification. Click Select. Emit from kotlin")
            }
            TRAY_ABOUT -> {
                QtApp.emit(EMIT_OPEN_ABOUT)
            }
        }
    }
}