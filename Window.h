#ifndef WINDOW_H
#define WINDOW_H

#include <QFileDialog>
#include <QObject>
#include <QWidget>
#include <QtGui>
#include "ui_Window.h"
#include <QMediaPlayer>

class Window : public QWidget, private Ui::Window {

    Q_OBJECT

    public:
        Window();

    private slots:
        void on_playButton_clicked();
        void on_stopButton_clicked();
        void on_pauseButton_clicked();
        void on_openFileButton_clicked();

    private:
        QMediaPlayer* mediaPlayer;
};

#endif // WINDOW_H
