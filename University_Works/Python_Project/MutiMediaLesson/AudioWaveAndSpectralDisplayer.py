import librosa
import matplotlib.pyplot as plt
import numpy as np

filename = librosa.example('nutcracker')


y1, sr1 = librosa.load('語聲.wav')
y2, sr2 = librosa.load('噪聲.wav')
y3, sr3 = librosa.load('歌聲.wav')

SoundList = [[y1,sr1,"1"], [y2,sr2,"2"], [y3,sr3,"3"]]

for package in SoundList:
    print(f'This is the ${package[2]} track\n')
    y = package[0]
    sr = package[1]

    #This is sample code from document tutorial
    tempo, beat_frames = librosa.beat.beat_track(y=y, sr=sr)
    print('Estimated tempo: {:.2f} beats per minute'.format(tempo))

    plt.figure()
    librosa.display.waveshow(y=y,sr=sr, color='pink')
    plt.title('Wave signal')
    plt.ylabel('Amplitude')
    plt.xlabel('Time')
    plt.show()

    data = librosa.amplitude_to_db(np.abs(librosa.stft(y)), ref=np.max)
    fig, ax = plt.subplots(1,1)
    img = librosa.display.specshow(data=data, sr=sr, x_axis='time', y_axis='linear')
    plt.ylim(0,8500)
    plt.title('Spetral View (Linear)')
    fig.colorbar(img,ax=ax, format="%+2.f dB")
    plt.show()

    beat_times = librosa.frames_to_time(beat_frames, sr=sr)