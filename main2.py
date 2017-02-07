import pyaudio
import wave
import audioop
import serial
import time

CHUNK = 1024
FORMAT = pyaudio.paInt16
CHANNELS = 2
RATE = 44100
file_name = "20sylTest.wav"
wf = wave.open(file_name,'rb')
ser = serial.Serial('COM3',baudrate=9600)
iterate = 0
p = pyaudio.PyAudio()

stream = p.open(format=FORMAT,
                channels=CHANNELS,
                rate=RATE,
                output=True,
                frames_per_buffer=CHUNK)
                
stream.start_stream()

data = wf.readframes(CHUNK)
mx = audioop.max(data,2)
time.sleep(15)

while data != '':
    data = wf.readframes(CHUNK)
    mx = audioop.max(data,2)
  # here's where you calculate the volume
    print int(mx) / 100
    if iterate == 45:
        iterate = 0
        ser.write(str(mx / 100))
    stream.write(data)
    iterate += 1

stream.stop_stream()
stream.close()
p.terminate()