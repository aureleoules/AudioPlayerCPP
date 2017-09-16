#include "Window.h"

bool isPaused = false;

Window::Window() {
    setupUi(this);
    mediaPlayer = new QMediaPlayer;
}

void Window::on_playButton_clicked() {
    if(filePath->text() == "") {
        mediaPlayer->setMedia(QUrl("http://here-and-now.info/audio/rickastley_artists.mp3"));
    } else {
        mediaPlayer->setMedia(QUrl::fromLocalFile(filePath->text()));
    }
    mediaPlayer->play();

}

void Window::on_stopButton_clicked() {
    mediaPlayer->stop();
}

void Window::on_openFileButton_clicked() {
    QString file = QFileDialog::getOpenFileName(this, tr("Open audio file"));

    if(file != NULL) {
        filePath->setText(file);
        on_playButton_clicked();
    }
}

void Window::on_pauseButton_clicked() {
    if(isPaused == true) {
        mediaPlayer->play();
        isPaused = false;
        pauseButton->setText("Pause");
    } else {
        mediaPlayer->pause();
        isPaused = true;
        pauseButton->setText("Resume");
    }
}
