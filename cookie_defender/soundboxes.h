#ifndef SOUNDBOXES_H
#define SOUNDBOXES_H

#include <QWidget>
#include <QMediaPlayer>
#include <QLabel>
#include <QString>
#include <QSlider>
#include <QTimer>
#include <QGridLayout>

class SoundBoxes : public QWidget
{
    Q_OBJECT
public:
    SoundBoxes(QWidget *parent = nullptr,int musicVolume = 0,int soundEffectVolume = 0,int indexMenu=0);
    QMediaPlayer *music,*sounds;
    bool isPlaying=false;
    QSlider *musicSlider,*sfx;

private slots:
    void volumeChanged(int);
    void sfxChanged(int);

private:
    QTimer *timer;
    QLabel *musicLabel,*sfxLabel;
};
#endif // SOUNDBOXES_H
