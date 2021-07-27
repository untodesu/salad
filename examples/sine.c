/*
 * sine.c
 * Created: 2021-07-27, 01:25:34.
 * Copyright (C) 2021, Kirill GPRB. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/salad.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>

#define NUM_SECONDS (1)
#define SAMPLE_RATE (44100)
#define BUF_SIZE    (NUM_SECONDS * SAMPLE_RATE)
#define SINE_FREQ   (60)

int main(void)
{
    ALCdevice *device;
    ALCcontext *context;
    ALshort data[BUF_SIZE * 2];
    ALuint buffer, source;

    if(!saladLoadAL()) {
        printf("Error loading AL functions!\n");
        return 1;
    }

    device = alcOpenDevice(NULL);
    context = alcCreateContext(device, NULL);
    alcMakeContextCurrent(context);

    for(int i = 0; i < BUF_SIZE; i++) {
        data[i * 2 + 0] = (ALshort)(sin(2.0 * 3.1415 * SINE_FREQ * i / BUF_SIZE) * SHRT_MAX);
        data[i * 2 + 1] = (ALshort)(sin(2.0 * 3.1415 * SINE_FREQ * i / BUF_SIZE) * SHRT_MAX) * -1;
    }

    alGenBuffers(1, &buffer);
    alBufferData(buffer, AL_FORMAT_STEREO16, data, sizeof(data), BUF_SIZE * 2);

    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    alSourcei(source, AL_LOOPING, AL_TRUE);
    alSourcePlay(source);

    printf("Press enter to exit");
    getchar();

    alSourceStop(source);
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);

    return 0;
}
