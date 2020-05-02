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

#ifndef JNIEXPORT_H
#define JNIEXPORT_H

#include <jni.h>

#ifndef _Included_com_keygenqt_kotlinqt_base_QtNative
#define _Included_com_keygenqt_kotlinqt_base_QtNative
#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT void JNICALL Java_com_keygenqt_kotlinqt_base_QtNative_action(JNIEnv *env, jobject objInstance, jobject listener);
JNIEXPORT void JNICALL Java_com_keygenqt_kotlinqt_base_QtNative_emit(JNIEnv *env, jobject objInstance, jint id, jstring params);
#ifdef __cplusplus
}
#endif
#endif

#endif // JNIEXPORT_H
