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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <about.h>
#include <QMessageBox>
#include <QStyle>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("KotlinQt");
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    windowAbout = new About(this);
    windowAbout->setModal(true);

    trayIcon = new QSystemTrayIcon(this);

    trayIcon->setIcon(QIcon(":data/images/icon.png"));

    QMenu * menu = new QMenu(this);
    viewWindow = new QAction(QString("Show App").toUtf8(), this);
    viewSelection = new QAction(QString("Select").toUtf8(), this);
    viewAbout = new QAction(QString("About").toUtf8(), this);
    quitAction = new QAction(QString("Quit").toUtf8(), this);

    connect(viewWindow, SIGNAL(triggered()), this, SLOT(triggeredWindow()));
    connect(viewSelection, SIGNAL(triggered()), this, SLOT(actionItemTray()));
    connect(viewAbout, SIGNAL(triggered()), this, SLOT(actionItemTray()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(quitApp()));

    menu->addAction(viewWindow);
    menu->addAction(viewSelection);
    menu->addSeparator();
    menu->addAction(viewAbout);
    menu->addAction(quitAction);

    trayIcon->setContextMenu(menu);
    trayIcon->show();

    QObject::connect(this, SIGNAL(valueChanged(int, QString)), this, SLOT(setValue(int, QString)));
}

void MainWindow::initListener(JniListener * listener) {
    this->listener = listener;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    if(this->isVisible()){
        event->ignore();
        this->hide();

        viewWindow->setText(QString("Show App").toUtf8());

        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
        trayIcon->showMessage(tr("KotlinQt"), QString("The application is minimized to tray.").toUtf8(), icon, 1000);
    }
}

void MainWindow::triggeredWindow() {
    if(!this->isVisible()){
        viewWindow->setText(QString("Hide App").toUtf8());
        this->show();
    } else {
        viewWindow->setText(QString("Show App").toUtf8());
        this->hide();
    }
}

void MainWindow::quitApp() {
    this->hide();
    this->close();
}

void MainWindow::actionItemTray() {
    QAction* action = qobject_cast<QAction *>(QObject::sender());
    this->listener->invoke("{type: 'actionItemTray', key: '"+action->text()+"'}");
}

void MainWindow::setValue(int id, QString params) {
    switch (id) {
        case 1: {
            QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
            trayIcon->showMessage(tr("KotlinQt"), params.toUtf8(), icon, 1000);
            break;
        }
        case 2: {
            windowAbout->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    windowAbout->size(),
                    qApp->desktop()->availableGeometry()
                )
            );
            windowAbout->show();
            break;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "qDebug()  << push Call to kotlin";
    this->listener->invoke("{type: 'qDebug', data: 'push Call to kotlin'}");
}
