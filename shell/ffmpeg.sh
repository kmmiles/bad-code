#!/usr/bin/env bash

# '/home/8OO8/Music/Norm_Corps_HAIZAI_RECORDS_vs_NORMCORPS/forcefeeded - HAIZAI RECORDS vs NORMCORPS - 15 makeme urs keep me urs.mp3
ALBUM="$HOME/Music/Norm_Corps_HAIZAI_RECORDS_vs_NORMCORPS"
#read  -p 'Album path: ' ALBUM
#read  -p 'GIF path: ' GIF
GIF="/tmp/foo.gif"

for SONG in "${ALBUM}"/*.mp3; do
    ffmpeg \
      -i "${SONG}" \
      -ignore_loop 0 \
      -i "${GIF}" \
      -vf "scale=trunc(iw/2)*2:trunc(ih/2)*2" \
      -shortest \
      -strict -2 \
      -c:v libx264 \
      -threads 4 \
      -c:a aac \
      -b:a 192k \
      -pix_fmt yuv420p \
      -shortest "${SONG%.mp3}".mp4
done
