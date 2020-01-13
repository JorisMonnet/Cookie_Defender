#ifndef SOUNDBOXES_H
#define SOUNDBOXES_H

#include <QWidget>
#include <QMediaPlayer>
#include <QLabel>
#include <QString>
#include <QSlider>
#include <QTimer>
class SoundBoxes : public QWidget
{
    Q_OBJECT
public:
    SoundBoxes(QWidget *parent = nullptr,int musicVolume = 0,int soundEffectVolume = 0,int indexMenu=0);
    QMediaPlayer *music;
    QMediaPlayer * sounds;
    bool isPlaying=false;
    QSlider *musicSlider;
    QSlider *sfx;
private slots:
    void volumeChanged(int vol);
    void sfxChanged(int sfx);

private:
    QTimer *timer;
    QLabel *musicLabel;
    QLabel *sfxlb;
};
#endif // SOUNDBOXES_H
