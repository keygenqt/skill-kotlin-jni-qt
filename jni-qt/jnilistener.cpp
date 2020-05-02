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

#include "jnilistener.h"

JniListener::JniListener(JavaVM * java, jobject listener)
{
    this->javaVM = java;
    this->listener = listener;

    JNIEnv * ENV;
    int stat = javaVM->GetEnv((void **)&ENV, JNI_VERSION_1_8);
    if (stat == JNI_EDETACHED) {
        javaVM->AttachCurrentThread((void **) &ENV, NULL);
    }
    if( ENV == NULL ) {
        return;
    }

    this->ENV = ENV;

    jclass listenerClassRef = ENV->GetObjectClass(listener);
    this->listenerEvent = ENV->GetMethodID( listenerClassRef, "invoke", "(Ljava/lang/String;)V" );
}

void JniListener::invoke(QString string) {

    jclass strClass = ENV->FindClass("java/lang/String");
    jmethodID ctorID = ENV->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    jstring encoding = ENV->NewStringUTF("GBK");

    jbyteArray bytes = ENV->NewByteArray(string.length());
    ENV->SetByteArrayRegion(bytes, 0, string.length(), reinterpret_cast<jbyte*>(string.toUtf8().data()));
    jstring str = (jstring)ENV->NewObject(strClass, ctorID, bytes, encoding);

    ENV->CallVoidMethod(this->listener, this->listenerEvent, str);
}
