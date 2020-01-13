#ifndef SOUNDBOXES_H
#define SOUNDBOXES_H

#include <QWidget>
#include <QMediaPlayer>
#include <QLabel>
#include <QString>
#include <QSlider>

class SoundBoxes : public QWidget
{
    Q_OBJECT
public:
    SoundBoxes(QWidget *parent = nullptr);
    int volume = 0;
    int soundEffectVolume = 0;
    /*QMediaPlayer * music;
    QMediaPlayer * sounds;*/

private slots:
    void volumeChanged(int vol);
    void sfxChanged(int sfx);

private:
    QSlider *musicSlider;
    QSlider *sfx;
    QLabel *musicLabel;
    QLabel *sfxlb;
};
#endif // SOUNDBOXES_H
