#pragma once

#include <QWidget>
class QSlider;
class QLabel;

class SoundBoxes : public QWidget
{
    Q_OBJECT
public:
    SoundBoxes(QWidget *parent = nullptr);
    int volume = 0;
    int soundEffect = 0;

public slots:
    void volumeChanged(int vol);
    void sfxChanged(int sfx);

private:
    QSlider *sound;
    QSlider *sfx;
    QLabel *soundlb;
    QLabel *sfxlb;
};
