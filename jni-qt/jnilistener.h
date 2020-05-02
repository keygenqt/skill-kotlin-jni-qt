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

#ifndef JNILISTENER_H
#define JNILISTENER_H

#include <jni.h>
#include <QString>

class JniListener
{
public:
    JniListener(JavaVM *, jobject);
    void invoke(QString);

private:
    JavaVM * javaVM;
    jobject listener;
    JNIEnv * ENV;
    jmethodID listenerEvent;
};

#endif // JNILISTENER_H
