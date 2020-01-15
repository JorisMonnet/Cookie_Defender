#include "soundboxes.h"

const int VOL_MIN = 0;
const int VOL_MAX = 99;

SoundBoxes::SoundBoxes(QWidget *parent,int musicVolume,int soundEffectVolume,int indexMenu)
    : QWidget(parent)
{
    timer = new QTimer(this);
    music = new QMediaPlayer();

    indexMenu?music->setMedia(QUrl("qrc:/sounds/jeu_versiofull.wav")):music->setMedia(QUrl("qrc:/sounds/jeu_menu.wav"));
    timer->start(static_cast<int>(music->duration()));
    connect(timer,&QTimer::timeout,this,[=]{
        if(isPlaying)
            music->play();
    });
    sounds = new QMediaPlayer();

    QGridLayout *layout = new QGridLayout(this);
    musicSlider = new QSlider(Qt::Horizontal, this);
    musicSlider->setRange(VOL_MIN, VOL_MAX);
    musicSlider->setSingleStep(1);
    musicSlider->setValue(musicVolume);
    music->setVolume(musicVolume);

    sfx = new QSlider(Qt::Horizontal, this);
    sfx->setRange(VOL_MIN, VOL_MAX);
    sfx->setSingleStep(1);
    sfx->setValue(soundEffectVolume);
    sounds->setVolume(soundEffectVolume);
    musicLabel = new QLabel(QString::number(musicVolume));
    sfxLabel = new QLabel(QString::number(soundEffectVolume));

    QLabel *soundtxt = new QLabel("Music");
    QLabel *sfxtxt = new QLabel("SFX");

    layout->addWidget(soundtxt, 0, 0);
    layout->addWidget(musicSlider, 0, 1);
    layout->addWidget(musicLabel, 0, 2);
    layout->addWidget(sfxtxt, 1, 0);
    layout->addWidget(sfx, 1, 1);
    layout->addWidget(sfxLabel, 1, 2);

    connect(musicSlider, &QSlider::valueChanged, this, &SoundBoxes::volumeChanged);
    connect(sfx, &QSlider::valueChanged, this, &SoundBoxes::sfxChanged);
}

void SoundBoxes::volumeChanged(int value)
{
    musicLabel->setText(QString::number(value));
    music->setVolume(value);
}

void SoundBoxes::sfxChanged(int value)
{
    sfxLabel->setText(QString::number(value));
    sounds->setVolume(value);
}
