/*
 * salad.c
 * Created: 2021-07-26, 23:24:18.
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
#include <stddef.h>

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
#define _POSIX 1
#endif

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN 1
#include <Windows.h>

#define OPENAL_LIBNAME "OpenAL32.lib"

static void *win32_loadfunc(const char *procname, void *arg)
{
    HMODULE hModule;
    if((hModule = (HMODULE)arg))
        return GetProcAddress(hModule, procname);
    return NULL;
}
#elif defined(_POSIX)
#include <dlfcn.h>

#if defined(__APPLE__)
#define OPENAL_LIBNAME "libopenal.dylib"
#else
#define OPENAL_LIBNAME "libopenal.so"
#endif

static void *posix_loadfunc(const char *procname, void *arg)
{
    if(arg)
        return dlsym(arg, procname);
    return NULL;
}
#endif

PFN_alEnable SALAD_alEnable = NULL;
PFN_alDisable SALAD_alDisable = NULL;
PFN_alIsEnabled SALAD_alIsEnabled = NULL;
PFN_alGetString SALAD_alGetString = NULL;
PFN_alGetBooleanv SALAD_alGetBooleanv = NULL;
PFN_alGetIntegerv SALAD_alGetIntegerv = NULL;
PFN_alGetFloatv SALAD_alGetFloatv = NULL;
PFN_alGetDoublev SALAD_alGetDoublev = NULL;
PFN_alGetBoolean SALAD_alGetBoolean = NULL;
PFN_alGetInteger SALAD_alGetInteger = NULL;
PFN_alGetFloat SALAD_alGetFloat = NULL;
PFN_alGetDouble SALAD_alGetDouble = NULL;
PFN_alGetError SALAD_alGetError = NULL;
PFN_alIsExtensionPresent SALAD_alIsExtensionPresent = NULL;
PFN_alGetProcAddress SALAD_alGetProcAddress = NULL;
PFN_alGetEnumValue SALAD_alGetEnumValue = NULL;
PFN_alListenerf SALAD_alListenerf = NULL;
PFN_alListener3f SALAD_alListener3f = NULL;
PFN_alListenerfv SALAD_alListenerfv = NULL;
PFN_alListeneri SALAD_alListeneri = NULL;
PFN_alListener3i SALAD_alListener3i = NULL;
PFN_alListeneriv SALAD_alListeneriv = NULL;
PFN_alGetListenerf SALAD_alGetListenerf = NULL;
PFN_alGetListener3f SALAD_alGetListener3f = NULL;
PFN_alGetListenerfv SALAD_alGetListenerfv = NULL;
PFN_alGetListeneri SALAD_alGetListeneri = NULL;
PFN_alGetListener3i SALAD_alGetListener3i = NULL;
PFN_alGetListeneriv SALAD_alGetListeneriv = NULL;
PFN_alGenSources SALAD_alGenSources = NULL;
PFN_alDeleteSources SALAD_alDeleteSources = NULL;
PFN_alIsSource SALAD_alIsSource = NULL;
PFN_alSourcef SALAD_alSourcef = NULL;
PFN_alSource3f SALAD_alSource3f = NULL;
PFN_alSourcefv SALAD_alSourcefv = NULL;
PFN_alSourcei SALAD_alSourcei = NULL;
PFN_alSource3i SALAD_alSource3i = NULL;
PFN_alSourceiv SALAD_alSourceiv = NULL;
PFN_alGetSourcef SALAD_alGetSourcef = NULL;
PFN_alGetSource3f SALAD_alGetSource3f = NULL;
PFN_alGetSourcefv SALAD_alGetSourcefv = NULL;
PFN_alGetSourcei SALAD_alGetSourcei = NULL;
PFN_alGetSource3i SALAD_alGetSource3i = NULL;
PFN_alGetSourceiv SALAD_alGetSourceiv = NULL;
PFN_alSourcePlayv SALAD_alSourcePlayv = NULL;
PFN_alSourceStopv SALAD_alSourceStopv = NULL;
PFN_alSourceRewindv SALAD_alSourceRewindv = NULL;
PFN_alSourcePausev SALAD_alSourcePausev = NULL;
PFN_alSourcePlay SALAD_alSourcePlay = NULL;
PFN_alSourceStop SALAD_alSourceStop = NULL;
PFN_alSourceRewind SALAD_alSourceRewind = NULL;
PFN_alSourcePause SALAD_alSourcePause = NULL;
PFN_alSourceQueueBuffers SALAD_alSourceQueueBuffers = NULL;
PFN_alSourceUnqueueBuffers SALAD_alSourceUnqueueBuffers = NULL;
PFN_alGenBuffers SALAD_alGenBuffers = NULL;
PFN_alDeleteBuffers SALAD_alDeleteBuffers = NULL;
PFN_alIsBuffer SALAD_alIsBuffer = NULL;
PFN_alBufferData SALAD_alBufferData = NULL;
PFN_alBufferf SALAD_alBufferf = NULL;
PFN_alBuffer3f SALAD_alBuffer3f = NULL;
PFN_alBufferfv SALAD_alBufferfv = NULL;
PFN_alBufferi SALAD_alBufferi = NULL;
PFN_alBuffer3i SALAD_alBuffer3i = NULL;
PFN_alBufferiv SALAD_alBufferiv = NULL;
PFN_alGetBufferf SALAD_alGetBufferf = NULL;
PFN_alGetBuffer3f SALAD_alGetBuffer3f = NULL;
PFN_alGetBufferfv SALAD_alGetBufferfv = NULL;
PFN_alGetBufferi SALAD_alGetBufferi = NULL;
PFN_alGetBuffer3i SALAD_alGetBuffer3i = NULL;
PFN_alGetBufferiv SALAD_alGetBufferiv = NULL;

PFN_alcCreateContext SALAD_alcCreateContext = NULL;
PFN_alcMakeContextCurrent SALAD_alcMakeContextCurrent = NULL;
PFN_alcProcessContext SALAD_alcProcessContext = NULL;
PFN_alcSuspendContext SALAD_alcSuspendContext = NULL;
PFN_alcDestroyContext SALAD_alcDestroyContext = NULL;
PFN_alcGetCurrentContext SALAD_alcGetCurrentContext = NULL;
PFN_alcGetContextsDevice SALAD_alcGetContextsDevice = NULL;
PFN_alcOpenDevice SALAD_alcOpenDevice = NULL;
PFN_alcCloseDevice SALAD_alcCloseDevice = NULL;
PFN_alcGetError SALAD_alcGetError = NULL;
PFN_alcIsExtensionPresent SALAD_alcIsExtensionPresent = NULL;
PFN_alcGetProcAddress SALAD_alcGetProcAddress = NULL;
PFN_alcGetEnumValue SALAD_alcGetEnumValue = NULL;
PFN_alcGetString SALAD_alcGetString = NULL;
PFN_alcGetIntegerv SALAD_alcGetIntegerv = NULL;
PFN_alcCaptureOpenDevice SALAD_alcCaptureOpenDevice = NULL;
PFN_alcCaptureCloseDevice SALAD_alcCaptureCloseDevice = NULL;
PFN_alcCaptureStart SALAD_alcCaptureStart = NULL;
PFN_alcCaptureStop SALAD_alcCaptureStop = NULL;
PFN_alcCaptureSamples SALAD_alcCaptureSamples = NULL;

int saladLoadAL(void)
{
    void *module;

#if defined(_WIN32)
    if((module = (void *)LoadLibraryA(OPENAL_LIBNAME)))
        return saladLoadALFunc(win32_loadfunc, module);
    return 0;
#elif defined(_POSIX)
    if((module = dlopen(OPENAL_LIBNAME, RTLD_LAZY)))
        return saladLoadALFunc(posix_loadfunc, module);
    return 0;
#endif

    return 0;
}

int saladLoadALFunc(SALAD_loadfunc_t loadfunc, void *arg)
{
    if(!loadfunc)
        return 0;

    SALAD_alEnable = loadfunc("alEnable", arg);
    SALAD_alDisable = loadfunc("alDisable", arg);
    SALAD_alIsEnabled = loadfunc("alIsEnabled", arg);
    SALAD_alGetString = loadfunc("alGetString", arg);
    SALAD_alGetBooleanv = loadfunc("alGetBooleanv", arg);
    SALAD_alGetIntegerv = loadfunc("alGetIntegerv", arg);
    SALAD_alGetFloatv = loadfunc("alGetFloatv", arg);
    SALAD_alGetDoublev = loadfunc("alGetDoublev", arg);
    SALAD_alGetBoolean = loadfunc("alGetBoolean", arg);
    SALAD_alGetInteger = loadfunc("alGetInteger", arg);
    SALAD_alGetFloat = loadfunc("alGetFloat", arg);
    SALAD_alGetDouble = loadfunc("alGetDouble", arg);
    SALAD_alGetError = loadfunc("alGetError", arg);
    SALAD_alIsExtensionPresent = loadfunc("alIsExtensionPresent", arg);
    SALAD_alGetProcAddress = loadfunc("alGetProcAddress", arg);
    SALAD_alGetEnumValue = loadfunc("alGetEnumValue", arg);
    SALAD_alListenerf = loadfunc("alListenerf", arg);
    SALAD_alListener3f = loadfunc("alListener3f", arg);
    SALAD_alListenerfv = loadfunc("alListenerfv", arg);
    SALAD_alListeneri = loadfunc("alListeneri", arg);
    SALAD_alListener3i = loadfunc("alListener3i", arg);
    SALAD_alListeneriv = loadfunc("alListeneriv", arg);
    SALAD_alGetListenerf = loadfunc("alGetListenerf", arg);
    SALAD_alGetListener3f = loadfunc("alGetListener3f", arg);
    SALAD_alGetListenerfv = loadfunc("alGetListenerfv", arg);
    SALAD_alGetListeneri = loadfunc("alGetListeneri", arg);
    SALAD_alGetListener3i = loadfunc("alGetListener3i", arg);
    SALAD_alGetListeneriv = loadfunc("alGetListeneriv", arg);
    SALAD_alGenSources = loadfunc("alGenSources", arg);
    SALAD_alDeleteSources = loadfunc("alDeleteSources", arg);
    SALAD_alIsSource = loadfunc("alIsSource", arg);
    SALAD_alSourcef = loadfunc("alSourcef", arg);
    SALAD_alSource3f = loadfunc("alSource3f", arg);
    SALAD_alSourcefv = loadfunc("alSourcefv", arg);
    SALAD_alSourcei = loadfunc("alSourcei", arg);
    SALAD_alSource3i = loadfunc("alSource3i", arg);
    SALAD_alSourceiv = loadfunc("alSourceiv", arg);
    SALAD_alGetSourcef = loadfunc("alGetSourcef", arg);
    SALAD_alGetSource3f = loadfunc("alGetSource3f", arg);
    SALAD_alGetSourcefv = loadfunc("alGetSourcefv", arg);
    SALAD_alGetSourcei = loadfunc("alGetSourcei", arg);
    SALAD_alGetSource3i = loadfunc("alGetSource3i", arg);
    SALAD_alGetSourceiv = loadfunc("alGetSourceiv", arg);
    SALAD_alSourcePlayv = loadfunc("alSourcePlayv", arg);
    SALAD_alSourceStopv = loadfunc("alSourceStopv", arg);
    SALAD_alSourceRewindv = loadfunc("alSourceRewindv", arg);
    SALAD_alSourcePausev = loadfunc("alSourcePausev", arg);
    SALAD_alSourcePlay = loadfunc("alSourcePlay", arg);
    SALAD_alSourceStop = loadfunc("alSourceStop", arg);
    SALAD_alSourceRewind = loadfunc("alSourceRewind", arg);
    SALAD_alSourcePause = loadfunc("alSourcePause", arg);
    SALAD_alSourceQueueBuffers = loadfunc("alSourceQueueBuffers", arg);
    SALAD_alSourceUnqueueBuffers = loadfunc("alSourceUnqueueBuffers", arg);
    SALAD_alGenBuffers = loadfunc("alGenBuffers", arg);
    SALAD_alDeleteBuffers = loadfunc("alDeleteBuffers", arg);
    SALAD_alIsBuffer = loadfunc("alIsBuffer", arg);
    SALAD_alBufferData = loadfunc("alBufferData", arg);
    SALAD_alBufferf = loadfunc("alBufferf", arg);
    SALAD_alBuffer3f = loadfunc("alBuffer3f", arg);
    SALAD_alBufferfv = loadfunc("alBufferfv", arg);
    SALAD_alBufferi = loadfunc("alBufferi", arg);
    SALAD_alBuffer3i = loadfunc("alBuffer3i", arg);
    SALAD_alBufferiv = loadfunc("alBufferiv", arg);
    SALAD_alGetBufferf = loadfunc("alGetBufferf", arg);
    SALAD_alGetBuffer3f = loadfunc("alGetBuffer3f", arg);
    SALAD_alGetBufferfv = loadfunc("alGetBufferfv", arg);
    SALAD_alGetBufferi = loadfunc("alGetBufferi", arg);
    SALAD_alGetBuffer3i = loadfunc("alGetBuffer3i", arg);
    SALAD_alGetBufferiv = loadfunc("alGetBufferiv", arg);

    SALAD_alcCreateContext = loadfunc("alcCreateContext", arg);
    SALAD_alcMakeContextCurrent = loadfunc("alcMakeContextCurrent", arg);
    SALAD_alcProcessContext = loadfunc("alcProcessContext", arg);
    SALAD_alcSuspendContext = loadfunc("alcSuspendContext", arg);
    SALAD_alcDestroyContext = loadfunc("alcDestroyContext", arg);
    SALAD_alcGetCurrentContext = loadfunc("alcGetCurrentContext", arg);
    SALAD_alcGetContextsDevice = loadfunc("alcGetContextsDevice", arg);
    SALAD_alcOpenDevice = loadfunc("alcOpenDevice", arg);
    SALAD_alcCloseDevice = loadfunc("alcCloseDevice", arg);
    SALAD_alcGetError = loadfunc("alcGetError", arg);
    SALAD_alcIsExtensionPresent = loadfunc("alcIsExtensionPresent", arg);
    SALAD_alcGetProcAddress = loadfunc("alcGetProcAddress", arg);
    SALAD_alcGetEnumValue = loadfunc("alcGetEnumValue", arg);
    SALAD_alcGetString = loadfunc("alcGetString", arg);
    SALAD_alcGetIntegerv = loadfunc("alcGetIntegerv", arg);
    SALAD_alcCaptureOpenDevice = loadfunc("alcCaptureOpenDevice", arg);
    SALAD_alcCaptureCloseDevice = loadfunc("alcCaptureCloseDevice", arg);
    SALAD_alcCaptureStart = loadfunc("alcCaptureStart", arg);
    SALAD_alcCaptureStop = loadfunc("alcCaptureStop", arg);
    SALAD_alcCaptureSamples = loadfunc("alcCaptureSamples", arg);

#if defined(SALAD_PARANOID)
    if(!SALAD_alEnable)
        return 0;
    if(!SALAD_alDisable)
        return 0;
    if(!SALAD_alIsEnabled)
        return 0;
    if(!SALAD_alGetString)
        return 0;
    if(!SALAD_alGetBooleanv)
        return 0;
    if(!SALAD_alGetIntegerv)
        return 0;
    if(!SALAD_alGetFloatv)
        return 0;
    if(!SALAD_alGetDoublev)
        return 0;
    if(!SALAD_alGetBoolean)
        return 0;
    if(!SALAD_alGetInteger)
        return 0;
    if(!SALAD_alGetFloat)
        return 0;
    if(!SALAD_alGetDouble)
        return 0;
    if(!SALAD_alGetError)
        return 0;
    if(!SALAD_alIsExtensionPresent)
        return 0;
    if(!SALAD_alGetProcAddress)
        return 0;
    if(!SALAD_alGetEnumValue)
        return 0;
    if(!SALAD_alListenerf)
        return 0;
    if(!SALAD_alListener3f)
        return 0;
    if(!SALAD_alListenerfv)
        return 0;
    if(!SALAD_alListeneri)
        return 0;
    if(!SALAD_alListener3i)
        return 0;
    if(!SALAD_alListeneriv)
        return 0;
    if(!SALAD_alGetListenerf)
        return 0;
    if(!SALAD_alGetListener3f)
        return 0;
    if(!SALAD_alGetListenerfv)
        return 0;
    if(!SALAD_alGetListeneri)
        return 0;
    if(!SALAD_alGetListener3i)
        return 0;
    if(!SALAD_alGetListeneriv)
        return 0;
    if(!SALAD_alGenSources)
        return 0;
    if(!SALAD_alDeleteSources)
        return 0;
    if(!SALAD_alIsSource)
        return 0;
    if(!SALAD_alSourcef)
        return 0;
    if(!SALAD_alSource3f)
        return 0;
    if(!SALAD_alSourcefv)
        return 0;
    if(!SALAD_alSourcei)
        return 0;
    if(!SALAD_alSource3i)
        return 0;
    if(!SALAD_alSourceiv)
        return 0;
    if(!SALAD_alGetSourcef)
        return 0;
    if(!SALAD_alGetSource3f)
        return 0;
    if(!SALAD_alGetSourcefv)
        return 0;
    if(!SALAD_alGetSourcei)
        return 0;
    if(!SALAD_alGetSource3i)
        return 0;
    if(!SALAD_alGetSourceiv)
        return 0;
    if(!SALAD_alSourcePlayv)
        return 0;
    if(!SALAD_alSourceStopv)
        return 0;
    if(!SALAD_alSourceRewindv)
        return 0;
    if(!SALAD_alSourcePausev)
        return 0;
    if(!SALAD_alSourcePlay)
        return 0;
    if(!SALAD_alSourceStop)
        return 0;
    if(!SALAD_alSourceRewind)
        return 0;
    if(!SALAD_alSourcePause)
        return 0;
    if(!SALAD_alSourceQueueBuffers)
        return 0;
    if(!SALAD_alSourceUnqueueBuffers)
        return 0;
    if(!SALAD_alGenBuffers)
        return 0;
    if(!SALAD_alDeleteBuffers)
        return 0;
    if(!SALAD_alIsBuffer)
        return 0;
    if(!SALAD_alBufferData)
        return 0;
    if(!SALAD_alBufferf)
        return 0;
    if(!SALAD_alBuffer3f)
        return 0;
    if(!SALAD_alBufferfv)
        return 0;
    if(!SALAD_alBufferi)
        return 0;
    if(!SALAD_alBuffer3i)
        return 0;
    if(!SALAD_alBufferiv)
        return 0;
    if(!SALAD_alGetBufferf)
        return 0;
    if(!SALAD_alGetBuffer3f)
        return 0;
    if(!SALAD_alGetBufferfv)
        return 0;
    if(!SALAD_alGetBufferi)
        return 0;
    if(!SALAD_alGetBuffer3i)
        return 0;
    if(!SALAD_alGetBufferiv)
        return 0;

    if(!SALAD_alcCreateContext)
        return 0;
    if(!SALAD_alcMakeContextCurrent)
        return 0;
    if(!SALAD_alcProcessContext)
        return 0;
    if(!SALAD_alcSuspendContext)
        return 0;
    if(!SALAD_alcDestroyContext)
        return 0;
    if(!SALAD_alcGetCurrentContext)
        return 0;
    if(!SALAD_alcGetContextsDevice)
        return 0;
    if(!SALAD_alcOpenDevice)
        return 0;
    if(!SALAD_alcCloseDevice)
        return 0;
    if(!SALAD_alcGetError)
        return 0;
    if(!SALAD_alcIsExtensionPresent)
        return 0;
    if(!SALAD_alcGetProcAddress)
        return 0;
    if(!SALAD_alcGetEnumValue)
        return 0;
    if(!SALAD_alcGetString)
        return 0;
    if(!SALAD_alcGetIntegerv)
        return 0;
    if(!SALAD_alcCaptureOpenDevice)
        return 0;
    if(!SALAD_alcCaptureCloseDevice)
        return 0;
    if(!SALAD_alcCaptureStart)
        return 0;
    if(!SALAD_alcCaptureStop)
        return 0;
    if(!SALAD_alcCaptureSamples)
        return 0;
#endif

    return 1;
}

