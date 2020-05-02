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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>
#include <jnilistener.h>
#include <about.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void initListener(JniListener *);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent * event);

private:
    JniListener* listener;

private slots:
    void triggeredWindow();
    void quitApp();
    void actionItemTray();
    void setValue(int id, QString params);

    void on_pushButton_clicked();

signals:
    void valueChanged(int id, QString params);

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;

    About * windowAbout;

    QAction * viewWindow;
    QAction * viewSelection;
    QAction * viewAbout;
    QAction * quitAction;
};
#endif // MAINWINDOW_H
