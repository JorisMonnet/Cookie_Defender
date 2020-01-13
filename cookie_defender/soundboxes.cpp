#include "soundboxes.h"

#include <QGridLayout>
#include <QTimer>

const int VOL_MIN = 0;
const int VOL_MAX = 99;

SoundBoxes::SoundBoxes(QWidget *parent)
    : QWidget(parent)
{
    /*QTimer *timer = new QTimer(this);
    music = new QMediaPlayer();
    music->setMedia(QUrl("../sounds/jeu_menu.wav"));
    music->play();
    timer->start(static_cast<int>(music->duration()));
    connect(timer,&QTimer::timeout,music,&QMediaPlayer::play);
    sounds = new QMediaPlayer();*/

    QGridLayout *layout = new QGridLayout(this);
    musicSlider = new QSlider(Qt::Horizontal, this);
    musicSlider->setRange(VOL_MIN, VOL_MAX);
    musicSlider->setSingleStep(1);
    musicSlider->setValue(volume);
    //music->setVolume(volume);
    sfx = new QSlider(Qt::Horizontal, this);
    sfx->setRange(VOL_MIN, VOL_MAX);
    sfx->setSingleStep(1);
    sfx->setValue(soundEffectVolume);
    //sounds->setVolume(soundEffectVolume);

    musicLabel = new QLabel(QString::number(volume));
    sfxlb = new QLabel(QString::number(soundEffectVolume));

    QLabel *soundtxt = new QLabel("Music");
    QLabel *sfxtxt = new QLabel("SFX");

    layout->addWidget(soundtxt, 0, 0);
    layout->addWidget(musicSlider, 0, 1);
    layout->addWidget(musicLabel, 0, 2);
    layout->addWidget(sfxtxt, 1, 0);
    layout->addWidget(sfx, 1, 1);
    layout->addWidget(sfxlb, 1, 2);

    connect(musicSlider, &QSlider::valueChanged, this, &SoundBoxes::volumeChanged);
    connect(sfx, &QSlider::valueChanged, this, &SoundBoxes::sfxChanged);
}

void SoundBoxes::volumeChanged(int value)
{
    musicLabel->setText(QString::number(value));
    //music->setVolume(value);
}

void SoundBoxes::sfxChanged(int value)
{
    sfxlb->setText(QString::number(value));
    //sounds->setVolume(value);
}
