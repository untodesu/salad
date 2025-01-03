/*
 * efx.h - ALC_EXT_EFX extension functions
 * Copyright (C) 2021-2025, Kirill Dmitrievich
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
#ifndef AL_EFX_H
#define AL_EFX_H
#define __efx_h_
#include <AL/al.h>

#define ALC_EXT_EFX_NAME "ALC_EXT_EFX"

#define ALC_EFX_MAJOR_VERSION   (0x20001)
#define ALC_EFX_MINOR_VERSION   (0x20002)
#define ALC_MAX_AUXILIARY_SENDS (0x20003)

#define AL_AIR_ABSORPTION_FACTOR                (0x20007)
#define AL_AUTOWAH_ATTACK_TIME                  (0x00001)
#define AL_AUTOWAH_PEAK_GAIN                    (0x00004)
#define AL_AUTOWAH_RELEASE_TIME                 (0x00002)
#define AL_AUTOWAH_RESONANCE                    (0x00003)
#define AL_AUXILIARY_SEND_FILTER                (0x20006)
#define AL_AUXILIARY_SEND_FILTER_GAIN_AUTO      (0x2000B)
#define AL_AUXILIARY_SEND_FILTER_GAINHF_AUTO    (0x2000C)
#define AL_BANDPASS_GAIN                        (0x00001)
#define AL_BANDPASS_GAINHF                      (0x00003)
#define AL_BANDPASS_GAINLF                      (0x00002)
#define AL_CHORUS_DELAY                         (0x00006)
#define AL_CHORUS_DEPTH                         (0x00004)
#define AL_CHORUS_FEEDBACK                      (0x00005)
#define AL_CHORUS_PHASE                         (0x00002)
#define AL_CHORUS_RATE                          (0x00003)
#define AL_CHORUS_WAVEFORM                      (0x00001)
#define AL_COMPRESSOR_ONOFF                     (0x00001)
#define AL_CONE_OUTER_GAINHF                    (0x20009)
#define AL_DIRECT_FILTER                        (0x20005)
#define AL_DIRECT_FILTER_GAINHF_AUTO            (0x2000A)
#define AL_DISTORTION_EDGE                      (0x00001)
#define AL_DISTORTION_EQBANDWIDTH               (0x00005)
#define AL_DISTORTION_EQCENTER                  (0x00004)
#define AL_DISTORTION_GAIN                      (0x00002)
#define AL_DISTORTION_LOWPASS_CUTOFF            (0x00003)
#define AL_ECHO_DAMPING                         (0x00003)
#define AL_ECHO_DELAY                           (0x00001)
#define AL_ECHO_FEEDBACK                        (0x00004)
#define AL_ECHO_LRDELAY                         (0x00002)
#define AL_ECHO_SPREAD                          (0x00005)
#define AL_EFFECT_AUTOWAH                       (0x0000A)
#define AL_EFFECT_CHORUS                        (0x00002)
#define AL_EFFECT_COMPRESSOR                    (0x0000B)
#define AL_EFFECT_DISTORTION                    (0x00003)
#define AL_EFFECT_ECHO                          (0x00004)
#define AL_EFFECT_EQUALIZER                     (0x0000C)
#define AL_EFFECT_FIRST_PARAMETER               (0x00000)
#define AL_EFFECT_FLANGER                       (0x00005)
#define AL_EFFECT_FREQUENCY_SHIFTER             (0x00006)
#define AL_EFFECT_LAST_PARAMETER                (0x08000)
#define AL_EFFECT_NULL                          (0x00000)
#define AL_EFFECT_PITCH_SHIFTER                 (0x00008)
#define AL_EFFECT_REVERB                        (0x00001)
#define AL_EFFECT_RING_MODULATOR                (0x00009)
#define AL_EFFECT_TYPE                          (0x08001)
#define AL_EFFECT_VOCAL_MORPHER                 (0x00007)
#define AL_EFFECTSLOT_AUXILIARY_SEND_AUTO       (0x00003)
#define AL_EFFECTSLOT_EFFECT                    (0x00001)
#define AL_EFFECTSLOT_GAIN                      (0x00002)
#define AL_EFFECTSLOT_NULL                      (0x00000)
#define AL_EQUALIZER_HIGH_CUTOFF                (0x0000A)
#define AL_EQUALIZER_HIGH_GAIN                  (0x00009)
#define AL_EQUALIZER_LOW_CUTOFF                 (0x00002)
#define AL_EQUALIZER_LOW_GAIN                   (0x00001)
#define AL_EQUALIZER_MID1_CENTER                (0x00004)
#define AL_EQUALIZER_MID1_GAIN                  (0x00003)
#define AL_EQUALIZER_MID1_WIDTH                 (0x00005)
#define AL_EQUALIZER_MID2_CENTER                (0x00007)
#define AL_EQUALIZER_MID2_GAIN                  (0x00006)
#define AL_EQUALIZER_MID2_WIDTH                 (0x00008)
#define AL_FILTER_BANDPASS                      (0x00003)
#define AL_FILTER_FIRST_PARAMETER               (0x00000)
#define AL_FILTER_HIGHPASS                      (0x00002)
#define AL_FILTER_LAST_PARAMETER                (0x08000)
#define AL_FILTER_LOWPASS                       (0x00001)
#define AL_FILTER_NULL                          (0x00000) 
#define AL_FILTER_TYPE                          (0x08001)
#define AL_FLANGER_DELAY                        (0x00006)
#define AL_FLANGER_DEPTH                        (0x00004)
#define AL_FLANGER_FEEDBACK                     (0x00005)
#define AL_FLANGER_PHASE                        (0x00002)
#define AL_FLANGER_RATE                         (0x00003)
#define AL_FLANGER_WAVEFORM                     (0x00001)
#define AL_FREQUENCY_SHIFTER_FREQUENCY          (0x00001)
#define AL_FREQUENCY_SHIFTER_LEFT_DIRECTION     (0x00002)
#define AL_FREQUENCY_SHIFTER_RIGHT_DIRECTION    (0x00003)
#define AL_HIGHPASS_GAIN                        (0x00001)
#define AL_HIGHPASS_GAINLF                      (0x00002)
#define AL_LOWPASS_GAIN                         (0x00001)
#define AL_LOWPASS_GAINHF                       (0x00002)
#define AL_METERS_PER_UNIT                      (0x20004)
#define AL_PITCH_SHIFTER_COARSE_TUNE            (0x00001)
#define AL_PITCH_SHIFTER_FINE_TUNE              (0x00002)
#define AL_REVERB_AIR_ABSORPTION_GAINHF         (0x0000B)
#define AL_REVERB_DECAY_HFLIMIT                 (0x0000D)
#define AL_REVERB_DECAY_HFRATIO                 (0x00006)
#define AL_REVERB_DECAY_TIME                    (0x00005)
#define AL_REVERB_DENSITY                       (0x00001)
#define AL_REVERB_DIFFUSION                     (0x00002)
#define AL_REVERB_GAIN                          (0x00003)
#define AL_REVERB_GAINHF                        (0x00004)
#define AL_REVERB_LATE_REVERB_DELAY             (0x0000A)
#define AL_REVERB_LATE_REVERB_GAIN              (0x00009)
#define AL_REVERB_REFLECTIONS_DELAY             (0x00008)
#define AL_REVERB_REFLECTIONS_GAIN              (0x00007)
#define AL_REVERB_ROOM_ROLLOFF_FACTOR           (0x0000C)
#define AL_RING_MODULATOR_FREQUENCY             (0x00001)
#define AL_RING_MODULATOR_HIGHPASS_CUTOFF       (0x00002)
#define AL_RING_MODULATOR_WAVEFORM              (0x00003)
#define AL_ROOM_ROLLOFF_FACTOR                  (0x20008)
#define AL_VOCAL_MORPHER_PHONEMEA               (0x00001)
#define AL_VOCAL_MORPHER_PHONEMEA_COARSE_TUNING (0x00002)
#define AL_VOCAL_MORPHER_PHONEMEB               (0x00003)
#define AL_VOCAL_MORPHER_PHONEMEB_COARSE_TUNING (0x00004)
#define AL_VOCAL_MORPHER_RATE                   (0x00006)
#define AL_VOCAL_MORPHER_WAVEFORM               (0x00005)

#define AL_AUTOWAH_DEFAULT_ATTACK_TIME                  (0.06f)
#define AL_AUTOWAH_DEFAULT_PEAK_GAIN                    (11.22f)
#define AL_AUTOWAH_DEFAULT_RELEASE_TIME                 (0.06f)
#define AL_AUTOWAH_DEFAULT_RESONANCE                    (1000.0f)
#define AL_AUTOWAH_MAX_ATTACK_TIME                      (1.0f)
#define AL_AUTOWAH_MAX_PEAK_GAIN                        (31621.0f)
#define AL_AUTOWAH_MAX_RELEASE_TIME                     (1.0f)
#define AL_AUTOWAH_MAX_RESONANCE                        (1000.0f)
#define AL_AUTOWAH_MIN_ATTACK_TIME                      (0.0001f)
#define AL_AUTOWAH_MIN_PEAK_GAIN                        (0.00003f)
#define AL_AUTOWAH_MIN_RELEASE_TIME                     (0.0001f)
#define AL_AUTOWAH_MIN_RESONANCE                        (2.0f)

#define AL_CHORUS_DEFAULT_DELAY                         (0.016f)
#define AL_CHORUS_DEFAULT_DEPTH                         (0.1f)
#define AL_CHORUS_DEFAULT_FEEDBACK                      (0.25f)
#define AL_CHORUS_DEFAULT_PHASE                         (90)
#define AL_CHORUS_DEFAULT_RATE                          (1.1f)
#define AL_CHORUS_DEFAULT_WAVEFORM                      (1)
#define AL_CHORUS_MAX_DELAY                             (0.016f)
#define AL_CHORUS_MAX_DEPTH                             (1.0f)
#define AL_CHORUS_MAX_FEEDBACK                          (1.0f)
#define AL_CHORUS_MAX_PHASE                             (180)
#define AL_CHORUS_MAX_RATE                              (10.0f)
#define AL_CHORUS_MAX_WAVEFORM                          (1)
#define AL_CHORUS_MIN_DELAY                             (0.0f)
#define AL_CHORUS_MIN_DEPTH                             (0.0f)
#define AL_CHORUS_MIN_FEEDBACK                          (-1.0f)
#define AL_CHORUS_MIN_PHASE                             (-180)
#define AL_CHORUS_MIN_RATE                              (0.0f)
#define AL_CHORUS_MIN_WAVEFORM                          (0)
#define AL_CHORUS_WAVEFORM_SINUSOID                     (0)
#define AL_CHORUS_WAVEFORM_TRIANGLE                     (1)

#define AL_COMPRESSOR_DEFAULT_ONOFF                     (1)
#define AL_COMPRESSOR_MAX_ONOFF                         (1)
#define AL_COMPRESSOR_MIN_ONOFF                         (0)

#define AL_DEFAULT_AIR_ABSORPTION_FACTOR                (0.0f)
#define AL_DEFAULT_AUXILIARY_SEND_FILTER_GAIN_AUTO      (AL_TRUE)
#define AL_DEFAULT_AUXILIARY_SEND_FILTER_GAINHF_AUTO    (AL_TRUE)
#define AL_DEFAULT_CONE_OUTER_GAINHF                    (1.0f)
#define AL_DEFAULT_DIRECT_FILTER_GAINHF_AUTO            (AL_TRUE)
#define AL_DEFAULT_METERS_PER_UNIT                      (1.0f)
#define AL_DEFAULT_ROOM_ROLLOFF_FACTOR                  (0.0f)

#define AL_DISTORTION_DEFAULT_EDGE                      (0.2f)
#define AL_DISTORTION_DEFAULT_EQBANDWIDTH               (3600.0f)
#define AL_DISTORTION_DEFAULT_EQCENTER                  (3600.0f)
#define AL_DISTORTION_DEFAULT_GAIN                      (0.05f)
#define AL_DISTORTION_DEFAULT_LOWPASS_CUTOFF            (8000.0f)
#define AL_DISTORTION_MAX_EDGE                          (1.0f)
#define AL_DISTORTION_MAX_EQBANDWIDTH                   (24000.0f)
#define AL_DISTORTION_MAX_EQCENTER                      (24000.0f)
#define AL_DISTORTION_MAX_GAIN                          (1.0f)
#define AL_DISTORTION_MAX_LOWPASS_CUTOFF                (24000.0f)
#define AL_DISTORTION_MIN_EDGE                          (0.0f)
#define AL_DISTORTION_MIN_EQBANDWIDTH                   (80.0f)
#define AL_DISTORTION_MIN_EQCENTER                      (80.0f)
#define AL_DISTORTION_MIN_GAIN                          (0.01f)
#define AL_DISTORTION_MIN_LOWPASS_CUTOFF                (80.0f)

#define AL_ECHO_DEFAULT_DAMPING                         (0.5f)
#define AL_ECHO_DEFAULT_DELAY                           (0.1f)
#define AL_ECHO_DEFAULT_FEEDBACK                        (0.5f)
#define AL_ECHO_DEFAULT_LRDELAY                         (0.1f)
#define AL_ECHO_DEFAULT_SPREAD                          (-1.0f)
#define AL_ECHO_MAX_DAMPING                             (0.99f)
#define AL_ECHO_MAX_DELAY                               (0.207f)
#define AL_ECHO_MAX_FEEDBACK                            (1.0f)
#define AL_ECHO_MAX_LRDELAY                             (0.404f)
#define AL_ECHO_MAX_SPREAD                              (1.0f)
#define AL_ECHO_MIN_DAMPING                             (0.0f)
#define AL_ECHO_MIN_DELAY                               (0.0f)
#define AL_ECHO_MIN_FEEDBACK                            (0.0f)
#define AL_ECHO_MIN_LRDELAY                             (0.0f)
#define AL_ECHO_MIN_SPREAD                              (-1.0f)

#define AL_EQUALIZER_DEFAULT_HIGH_CUTOFF                (6000.0f)
#define AL_EQUALIZER_DEFAULT_HIGH_GAIN                  (1.0f)
#define AL_EQUALIZER_DEFAULT_LOW_CUTOFF                 (200.0f)
#define AL_EQUALIZER_DEFAULT_LOW_GAIN                   (1.0f)
#define AL_EQUALIZER_DEFAULT_MID1_CENTER                (500.0f)
#define AL_EQUALIZER_DEFAULT_MID1_GAIN                  (1.0f)
#define AL_EQUALIZER_DEFAULT_MID1_WIDTH                 (1.0f)
#define AL_EQUALIZER_DEFAULT_MID2_CENTER                (3000.0f)
#define AL_EQUALIZER_DEFAULT_MID2_GAIN                  (1.0f)
#define AL_EQUALIZER_DEFAULT_MID2_WIDTH                 (1.0f)
#define AL_EQUALIZER_MAX_HIGH_CUTOFF                    (16000.0f)
#define AL_EQUALIZER_MAX_HIGH_GAIN                      (7.943f)
#define AL_EQUALIZER_MAX_LOW_CUTOFF                     (800.0f)
#define AL_EQUALIZER_MAX_LOW_GAIN                       (7.943f)
#define AL_EQUALIZER_MAX_MID1_CENTER                    (3000.0f)
#define AL_EQUALIZER_MAX_MID1_GAIN                      (7.943f)
#define AL_EQUALIZER_MAX_MID1_WIDTH                     (1.0f)
#define AL_EQUALIZER_MAX_MID2_CENTER                    (8000.0f)
#define AL_EQUALIZER_MAX_MID2_GAIN                      (7.943f)
#define AL_EQUALIZER_MAX_MID2_WIDTH                     (1.0f)
#define AL_EQUALIZER_MIN_HIGH_CUTOFF                    (4000.0f)
#define AL_EQUALIZER_MIN_HIGH_GAIN                      (0.126f)
#define AL_EQUALIZER_MIN_LOW_CUTOFF                     (50.0f)
#define AL_EQUALIZER_MIN_LOW_GAIN                       (0.126f)
#define AL_EQUALIZER_MIN_MID1_CENTER                    (200.0f)
#define AL_EQUALIZER_MIN_MID1_GAIN                      (0.126f)
#define AL_EQUALIZER_MIN_MID1_WIDTH                     (0.01f)
#define AL_EQUALIZER_MIN_MID2_CENTER                    (1000.0f)
#define AL_EQUALIZER_MIN_MID2_GAIN                      (0.126f)
#define AL_EQUALIZER_MIN_MID2_WIDTH                     (0.01f)

#define AL_FLANGER_DEFAULT_DELAY                        (0.002f)
#define AL_FLANGER_DEFAULT_DEPTH                        (1.0f)
#define AL_FLANGER_DEFAULT_FEEDBACK                     (-0.5f)
#define AL_FLANGER_DEFAULT_PHASE                        (0)
#define AL_FLANGER_DEFAULT_RATE                         (0.27f)
#define AL_FLANGER_DEFAULT_WAVEFORM                     (1)
#define AL_FLANGER_MAX_DELAY                            (0.004f)
#define AL_FLANGER_MAX_DEPTH                            (1.0f)
#define AL_FLANGER_MAX_FEEDBACK                         (1.0f)
#define AL_FLANGER_MAX_PHASE                            (180)
#define AL_FLANGER_MAX_RATE                             (10.0f)
#define AL_FLANGER_MAX_WAVEFORM                         (1)
#define AL_FLANGER_MIN_DELAY                            (0.0f)
#define AL_FLANGER_MIN_DEPTH                            (0.0f)
#define AL_FLANGER_MIN_FEEDBACK                         (-1.0f)
#define AL_FLANGER_MIN_PHASE                            (-180)
#define AL_FLANGER_MIN_RATE                             (0.0f)
#define AL_FLANGER_MIN_WAVEFORM                         (0)
#define AL_FLANGER_WAVEFORM_SINUSOID                    (0)
#define AL_FLANGER_WAVEFORM_TRIANGLE                    (1)

#define AL_FREQUENCY_SHIFTER_DEFAULT_FREQUENCY          (0.0f)
#define AL_FREQUENCY_SHIFTER_DEFAULT_LEFT_DIRECTION     (0)
#define AL_FREQUENCY_SHIFTER_DEFAULT_RIGHT_DIRECTION    (0)
#define AL_FREQUENCY_SHIFTER_DIRECTION_DOWN             (0)
#define AL_FREQUENCY_SHIFTER_DIRECTION_OFF              (2)
#define AL_FREQUENCY_SHIFTER_DIRECTION_UP               (1)
#define AL_FREQUENCY_SHIFTER_MAX_FREQUENCY              (24000.0f)
#define AL_FREQUENCY_SHIFTER_MAX_LEFT_DIRECTION         (2)
#define AL_FREQUENCY_SHIFTER_MAX_RIGHT_DIRECTION        (2)
#define AL_FREQUENCY_SHIFTER_MIN_FREQUENCY              (0.0f)
#define AL_FREQUENCY_SHIFTER_MIN_LEFT_DIRECTION         (0)
#define AL_FREQUENCY_SHIFTER_MIN_RIGHT_DIRECTION        (0)

#define AL_MAX_AIR_ABSORPTION_FACTOR                    (10.0f)
#define AL_MAX_AUXILIARY_SEND_FILTER_GAIN_AUTO          (AL_TRUE)
#define AL_MAX_AUXILIARY_SEND_FILTER_GAINHF_AUTO        (AL_TRUE)
#define AL_MAX_CONE_OUTER_GAINHF                        (1.0f)
#define AL_MAX_DIRECT_FILTER_GAINHF_AUTO                (AL_TRUE)
#define AL_MAX_METERS_PER_UNIT                          (FLT_MAX)
#define AL_MAX_ROOM_ROLLOFF_FACTOR                      (10.0f)
#define AL_MIN_AIR_ABSORPTION_FACTOR                    (0.0f)
#define AL_MIN_AUXILIARY_SEND_FILTER_GAIN_AUTO          (AL_FALSE)
#define AL_MIN_AUXILIARY_SEND_FILTER_GAINHF_AUTO        (AL_FALSE)
#define AL_MIN_CONE_OUTER_GAINHF                        (0.0f)
#define AL_MIN_DIRECT_FILTER_GAINHF_AUTO                (AL_FALSE)
#define AL_MIN_METERS_PER_UNIT                          (FLT_MIN)
#define AL_MIN_ROOM_ROLLOFF_FACTOR                      (0.0f)

#define AL_PITCH_SHIFTER_DEFAULT_COARSE_TUNE            (12)
#define AL_PITCH_SHIFTER_DEFAULT_FINE_TUNE              (0)
#define AL_PITCH_SHIFTER_MAX_COARSE_TUNE                (12)
#define AL_PITCH_SHIFTER_MAX_FINE_TUNE                  (50)
#define AL_PITCH_SHIFTER_MIN_COARSE_TUNE                (-12)
#define AL_PITCH_SHIFTER_MIN_FINE_TUNE                  (-50)

#define AL_REVERB_DEFAULT_AIR_ABSORPTION_GAINHF         (0.994f)
#define AL_REVERB_DEFAULT_DECAY_HFLIMIT                 (AL_TRUE)
#define AL_REVERB_DEFAULT_DECAY_HFRATIO                 (0.83f)
#define AL_REVERB_DEFAULT_DECAY_TIME                    (1.49f)
#define AL_REVERB_DEFAULT_DENSITY                       (1.0f)
#define AL_REVERB_DEFAULT_DIFFUSION                     (1.0f)
#define AL_REVERB_DEFAULT_GAIN                          (0.32f)
#define AL_REVERB_DEFAULT_GAINHF                        (0.89f)
#define AL_REVERB_DEFAULT_LATE_REVERB_DELAY             (0.011f)
#define AL_REVERB_DEFAULT_LATE_REVERB_GAIN              (1.26f)
#define AL_REVERB_DEFAULT_REFLECTIONS_DELAY             (0.007f)
#define AL_REVERB_DEFAULT_REFLECTIONS_GAIN              (0.05f)
#define AL_REVERB_DEFAULT_ROOM_ROLLOFF_FACTOR           (0.0f)
#define AL_REVERB_MAX_AIR_ABSORPTION_GAINHF             (1.0f)
#define AL_REVERB_MAX_DECAY_HFLIMIT                     (AL_TRUE)
#define AL_REVERB_MAX_DECAY_HFRATIO                     (2.0f)
#define AL_REVERB_MAX_DECAY_TIME                        (20.0f)
#define AL_REVERB_MAX_DENSITY                           (1.0f)
#define AL_REVERB_MAX_DIFFUSION                         (1.0f)
#define AL_REVERB_MAX_GAIN                              (1.0f)
#define AL_REVERB_MAX_GAINHF                            (1.0f)
#define AL_REVERB_MAX_LATE_REVERB_DELAY                 (0.1f)
#define AL_REVERB_MAX_LATE_REVERB_GAIN                  (10.0f)
#define AL_REVERB_MAX_REFLECTIONS_DELAY                 (0.3f)
#define AL_REVERB_MAX_REFLECTIONS_GAIN                  (3.16f)
#define AL_REVERB_MAX_ROOM_ROLLOFF_FACTOR               (10.0f)
#define AL_REVERB_MIN_AIR_ABSORPTION_GAINHF             (0.892f)
#define AL_REVERB_MIN_DECAY_HFLIMIT                     (AL_FALSE)
#define AL_REVERB_MIN_DECAY_HFRATIO                     (0.1f)
#define AL_REVERB_MIN_DECAY_TIME                        (0.1f)
#define AL_REVERB_MIN_DENSITY                           (0.0f)
#define AL_REVERB_MIN_DIFFUSION                         (0.0f)
#define AL_REVERB_MIN_GAIN                              (0.0f)
#define AL_REVERB_MIN_GAINHF                            (0.0f)
#define AL_REVERB_MIN_LATE_REVERB_DELAY                 (0.0f)
#define AL_REVERB_MIN_LATE_REVERB_GAIN                  (0.0f)
#define AL_REVERB_MIN_REFLECTIONS_DELAY                 (0.0f)
#define AL_REVERB_MIN_REFLECTIONS_GAIN                  (0.0f)
#define AL_REVERB_MIN_ROOM_ROLLOFF_FACTOR               (0.0f)

#define AL_RING_MODULATOR_DEFAULT_FREQUENCY             (440.0f)
#define AL_RING_MODULATOR_DEFAULT_HIGHPASS_CUTOFF       (800.0f)
#define AL_RING_MODULATOR_DEFAULT_WAVEFORM              (0)
#define AL_RING_MODULATOR_MAX_FREQUENCY                 (8000.0f)
#define AL_RING_MODULATOR_MAX_HIGHPASS_CUTOFF           (24000.0f)
#define AL_RING_MODULATOR_MAX_WAVEFORM                  (2)
#define AL_RING_MODULATOR_MIN_FREQUENCY                 (0.0f)
#define AL_RING_MODULATOR_MIN_HIGHPASS_CUTOFF           (0.0f)
#define AL_RING_MODULATOR_MIN_WAVEFORM                  (0)
#define AL_RING_MODULATOR_SAWTOOTH                      (1)
#define AL_RING_MODULATOR_SINUSOID                      (0)
#define AL_RING_MODULATOR_SQUARE                        (2)

#define AL_VOCAL_MORPHER_DEFAULT_PHONEMEA               (0)
#define AL_VOCAL_MORPHER_DEFAULT_PHONEMEA_COARSE_TUNING (0)
#define AL_VOCAL_MORPHER_DEFAULT_PHONEMEB               (10)
#define AL_VOCAL_MORPHER_DEFAULT_PHONEMEB_COARSE_TUNING (0)
#define AL_VOCAL_MORPHER_DEFAULT_RATE                   (1.41f)
#define AL_VOCAL_MORPHER_DEFAULT_WAVEFORM               (0)
#define AL_VOCAL_MORPHER_MAX_PHONEMEA                   (29)
#define AL_VOCAL_MORPHER_MAX_PHONEMEA_COARSE_TUNING     (24)
#define AL_VOCAL_MORPHER_MAX_PHONEMEB                   (29)
#define AL_VOCAL_MORPHER_MAX_PHONEMEB_COARSE_TUNING     (24)
#define AL_VOCAL_MORPHER_MAX_RATE                       (10.0f)
#define AL_VOCAL_MORPHER_MAX_WAVEFORM                   (2)
#define AL_VOCAL_MORPHER_MIN_PHONEMEA                   (0)
#define AL_VOCAL_MORPHER_MIN_PHONEMEA_COARSE_TUNING     (-24)
#define AL_VOCAL_MORPHER_MIN_PHONEMEB                   (0)
#define AL_VOCAL_MORPHER_MIN_PHONEMEB_COARSE_TUNING     (-24)
#define AL_VOCAL_MORPHER_MIN_RATE                       (0.0f)
#define AL_VOCAL_MORPHER_MIN_WAVEFORM                   (0)
#define AL_VOCAL_MORPHER_PHONEME_A                      (0)
#define AL_VOCAL_MORPHER_PHONEME_AA                     (5)
#define AL_VOCAL_MORPHER_PHONEME_AE                     (6)
#define AL_VOCAL_MORPHER_PHONEME_AH                     (7)
#define AL_VOCAL_MORPHER_PHONEME_AO                     (8)
#define AL_VOCAL_MORPHER_PHONEME_B                      (15)
#define AL_VOCAL_MORPHER_PHONEME_D                      (16)
#define AL_VOCAL_MORPHER_PHONEME_E                      (1)
#define AL_VOCAL_MORPHER_PHONEME_EH                     (9)
#define AL_VOCAL_MORPHER_PHONEME_ER                     (10)
#define AL_VOCAL_MORPHER_PHONEME_F                      (17)
#define AL_VOCAL_MORPHER_PHONEME_G                      (18)
#define AL_VOCAL_MORPHER_PHONEME_I                      (2)
#define AL_VOCAL_MORPHER_PHONEME_IH                     (11)
#define AL_VOCAL_MORPHER_PHONEME_IY                     (12)
#define AL_VOCAL_MORPHER_PHONEME_J                      (19)
#define AL_VOCAL_MORPHER_PHONEME_K                      (20)
#define AL_VOCAL_MORPHER_PHONEME_L                      (21)
#define AL_VOCAL_MORPHER_PHONEME_M                      (22)
#define AL_VOCAL_MORPHER_PHONEME_N                      (23)
#define AL_VOCAL_MORPHER_PHONEME_O                      (3)
#define AL_VOCAL_MORPHER_PHONEME_P                      (24)
#define AL_VOCAL_MORPHER_PHONEME_R                      (25)
#define AL_VOCAL_MORPHER_PHONEME_S                      (26)
#define AL_VOCAL_MORPHER_PHONEME_T                      (27)
#define AL_VOCAL_MORPHER_PHONEME_U                      (4)
#define AL_VOCAL_MORPHER_PHONEME_UH                     (13)
#define AL_VOCAL_MORPHER_PHONEME_UW                     (14)
#define AL_VOCAL_MORPHER_PHONEME_V                      (28)
#define AL_VOCAL_MORPHER_PHONEME_Z                      (29)
#define AL_VOCAL_MORPHER_WAVEFORM_SAWTOOTH              (2)
#define AL_VOCAL_MORPHER_WAVEFORM_SINUSOID              (0)
#define AL_VOCAL_MORPHER_WAVEFORM_TRIANGLE              (1)

#define BANDPASS_DEFAULT_GAIN                           (1.0f)
#define BANDPASS_DEFAULT_GAINHF                         (1.0f)
#define BANDPASS_DEFAULT_GAINLF                         (1.0f)
#define BANDPASS_MAX_GAIN                               (1.0f)
#define BANDPASS_MAX_GAINHF                             (1.0f)
#define BANDPASS_MAX_GAINLF                             (1.0f)
#define BANDPASS_MIN_GAIN                               (0.0f)
#define BANDPASS_MIN_GAINHF                             (0.0f)
#define BANDPASS_MIN_GAINLF                             (0.0f)

#define HIGHPASS_DEFAULT_GAIN                           (1.0f)
#define HIGHPASS_DEFAULT_GAINLF                         (1.0f)
#define HIGHPASS_MAX_GAIN                               (1.0f)
#define HIGHPASS_MAX_GAINLF                             (1.0f)
#define HIGHPASS_MIN_GAIN                               (0.0f)
#define HIGHPASS_MIN_GAINLF                             (0.0f)

#define LOWPASS_DEFAULT_GAIN                            (1.0f)
#define LOWPASS_DEFAULT_GAINHF                          (1.0f)
#define LOWPASS_MAX_GAIN                                (1.0f)
#define LOWPASS_MAX_GAINHF                              (1.0f)
#define LOWPASS_MIN_GAIN                                (0.0f)
#define LOWPASS_MIN_GAINHF                              (0.0f)

typedef ALboolean (AL_APIENTRY *PFN_alIsEffect)(ALuint eid);
typedef ALboolean (AL_APIENTRY *PFN_alIsFilter)(ALuint fid);
typedef void (AL_APIENTRY *PFN_alDeleteEffects)(ALsizei n, ALuint *effects);
typedef void (AL_APIENTRY *PFN_alDeleteFilters)(ALsizei n, ALuint *filters);
typedef void (AL_APIENTRY *PFN_alEffectf)(ALuint eid, ALenum param, ALfloat value); 
typedef void (AL_APIENTRY *PFN_alEffectfv)(ALuint eid, ALenum param, ALfloat *values); 
typedef void (AL_APIENTRY *PFN_alEffecti)(ALuint eid, ALenum param, ALint value); 
typedef void (AL_APIENTRY *PFN_alEffectiv)(ALuint eid, ALenum param, ALint *values); 
typedef void (AL_APIENTRY *PFN_alFilterf)(ALuint fid, ALenum param, ALfloat value); 
typedef void (AL_APIENTRY *PFN_alFilterfv)(ALuint fid, ALenum param, ALfloat *values); 
typedef void (AL_APIENTRY *PFN_alFilteri)(ALuint fid, ALenum param, ALint value); 
typedef void (AL_APIENTRY *PFN_alFilteriv)(ALuint fid, ALenum param, ALint *values); 
typedef void (AL_APIENTRY *PFN_alGenEffects)(ALsizei n, ALuint *effects);
typedef void (AL_APIENTRY *PFN_alGenFilters)(ALsizei n, ALuint *filters); 
typedef void (AL_APIENTRY *PFN_alGetEffectf)(ALuint eid, ALenum pname, ALfloat *value);
typedef void (AL_APIENTRY *PFN_alGetEffectfv)(ALuint eid, ALenum pname, ALfloat *values);
typedef void (AL_APIENTRY *PFN_alGetEffecti)(ALuint eid, ALenum pname, ALint *value);
typedef void (AL_APIENTRY *PFN_alGetEffectiv)(ALuint eid, ALenum pname, ALint *values);
typedef void (AL_APIENTRY *PFN_alGetFilterf)(ALuint fid, ALenum pname, ALfloat *value);
typedef void (AL_APIENTRY *PFN_alGetFilterfv)(ALuint fid, ALenum pname, ALfloat *values);
typedef void (AL_APIENTRY *PFN_alGetFilteri)(ALuint fid, ALenum pname, ALint *value);
typedef void (AL_APIENTRY *PFN_alGetFilteriv)(ALuint fid, ALenum pname, ALint *values);

SALAD_EXTERN PFN_alDeleteEffects    SALAD_alDeleteEffects;
SALAD_EXTERN PFN_alDeleteFilters    SALAD_alDeleteFilters;
SALAD_EXTERN PFN_alEffectf          SALAD_alEffectf; 
SALAD_EXTERN PFN_alEffectfv         SALAD_alEffectfv; 
SALAD_EXTERN PFN_alEffecti          SALAD_alEffecti; 
SALAD_EXTERN PFN_alEffectiv         SALAD_alEffectiv; 
SALAD_EXTERN PFN_alFilterf          SALAD_alFilterf; 
SALAD_EXTERN PFN_alFilterfv         SALAD_alFilterfv; 
SALAD_EXTERN PFN_alFilteri          SALAD_alFilteri; 
SALAD_EXTERN PFN_alFilteriv         SALAD_alFilteriv; 
SALAD_EXTERN PFN_alGenEffects       SALAD_alGenEffects;
SALAD_EXTERN PFN_alGenFilters       SALAD_alGenFilters; 
SALAD_EXTERN PFN_alGetEffectf       SALAD_alGetEffectf;
SALAD_EXTERN PFN_alGetEffectfv      SALAD_alGetEffectfv;
SALAD_EXTERN PFN_alGetEffecti       SALAD_alGetEffecti;
SALAD_EXTERN PFN_alGetEffectiv      SALAD_alGetEffectiv;
SALAD_EXTERN PFN_alGetFilterf       SALAD_alGetFilterf;
SALAD_EXTERN PFN_alGetFilterfv      SALAD_alGetFilterfv;
SALAD_EXTERN PFN_alGetFilteri       SALAD_alGetFilteri;
SALAD_EXTERN PFN_alGetFilteriv      SALAD_alGetFilteriv;
SALAD_EXTERN PFN_alIsEffect         SALAD_alIsEffect;
SALAD_EXTERN PFN_alIsFilter         SALAD_alIsFilter;

#define alDeleteEffects SALAD_alDeleteEffects
#define alDeleteFilters SALAD_alDeleteFilters
#define alEffectf       SALAD_alEffectf 
#define alEffectfv      SALAD_alEffectfv 
#define alEffecti       SALAD_alEffecti 
#define alEffectiv      SALAD_alEffectiv 
#define alFilterf       SALAD_alFilterf 
#define alFilterfv      SALAD_alFilterfv 
#define alFilteri       SALAD_alFilteri 
#define alFilteriv      SALAD_alFilteriv 
#define alGenEffects    SALAD_alGenEffects
#define alGenFilters    SALAD_alGenFilters 
#define alGetEffectf    SALAD_alGetEffectf
#define alGetEffectfv   SALAD_alGetEffectfv
#define alGetEffecti    SALAD_alGetEffecti
#define alGetEffectiv   SALAD_alGetEffectiv
#define alGetFilterf    SALAD_alGetFilterf
#define alGetFilterfv   SALAD_alGetFilterfv
#define alGetFilteri    SALAD_alGetFilteri
#define alGetFilteriv   SALAD_alGetFilteriv
#define alIsEffect      SALAD_alIsEffect
#define alIsFilter      SALAD_alIsFilter

#endif
