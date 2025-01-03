/*
 * mains.c - simulate mains hum with OpenAL
 * Copyright (C) 2021-2024, Kirill Dmitrievich
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

#define DURATION    1
#define SAMPLERATE  8000
#define SNDSIZE     (DURATION*SAMPLERATE)

typedef ALshort snd_t[SNDSIZE];

static void generate_snd(snd_t sndbuffer)
{
    int n;
    double s;

    for(n = 0; n < SNDSIZE; ++n) {
        s = 0.0;
        s += 1.0 * sin(2.0 * 3.1415 * 50.0  * n / SNDSIZE);
        s += 2.0 * sin(2.0 * 3.1415 * 100.0 * n / SNDSIZE);
        s += 1.0 * sin(2.0 * 3.1415 * 200.0 * n / SNDSIZE);
        s += 0.5 * sin(2.0 * 3.1415 * 400.0 * n / SNDSIZE);

        /* Clamp into the correct range */
        if(s < -1.0) s = -1.0;
        if(s > +1.0) s = +1.0;

        sndbuffer[n] = (ALshort)(s * SHRT_MAX);
    }
}

int main(void)
{
    ALCdevice *device;
    ALCcontext *context;
    ALuint buffer, source;
    snd_t sndbuffer;

    if(!saladLoadALdefault()) {
        fprintf(stderr, "salad: load failed\n");
        return 1;
    }

    device = alcOpenDevice(NULL);
    context = alcCreateContext(device, NULL);
    alcMakeContextCurrent(context);

    generate_snd(sndbuffer);

    alGenBuffers(1, &buffer);
    alBufferData(buffer, AL_FORMAT_MONO16, sndbuffer, sizeof(sndbuffer), SNDSIZE);

    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    alSourcei(source, AL_LOOPING, AL_TRUE);
    alSourcePlay(source);

    fprintf(stderr, "press enter to stop");
    getchar();

    alSourceStop(source);
    alDeleteSources(1, &source);

    alDeleteBuffers(1, &buffer);

    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);

    return 0;
}
