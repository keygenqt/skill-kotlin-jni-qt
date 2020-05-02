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

#include "jniexport.h"
#include "mainwindow.h"

#include <QApplication>

MainWindow *MAIN;

JNIEXPORT void JNICALL Java_com_keygenqt_kotlinqt_base_QtNative_action(JNIEnv *env, jobject objInstance, jobject listener) {

    JavaVM * savedVM = NULL;
    env->GetJavaVM( &savedVM );

    JniListener jniListener = JniListener(savedVM, listener);

    int arg = 1;
    QApplication a(arg, {});
    MainWindow w;
    MAIN = &w;
    MAIN->initListener(&jniListener);
    a.exec();
    return;
}

JNIEXPORT void JNICALL Java_com_keygenqt_kotlinqt_base_QtNative_emit(JNIEnv *env, jobject objInstance, jint id, jstring params) {
    jboolean isCopy;
    const char *convertedValue = (env)->GetStringUTFChars(params, &isCopy);
    ;    emit MAIN->valueChanged(id, QString::fromUtf8(convertedValue));
    return;
}
