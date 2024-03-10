/*

  ESP32 FFT
  =========

  This provides a vanilla radix-2 FFT implementation and a test example.

  Author
  ------

  This code was written by [Robin Scheibler](http://www.robinscheibler.org)
  during rainy days in October 2017.

  License
  -------

  Copyright (c) 2017 Robin Scheibler

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

*/
#ifndef __ESP32_FFT_H__
#define __ESP32_FFT_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    ESP32_FFT_REAL,
    ESP32_FFT_COMPLEX
} esp32_fft_type_t;

typedef enum
{
    ESP32_FFT_FORWARD,
    ESP32_FFT_BACKWARD
} esp32_fft_direction_t;

#define ESP32_FFT_OWN_INPUT_MEM 1
#define ESP32_FFT_OWN_OUTPUT_MEM 2

typedef struct
{
    int size;               // FFT size
    float *input;           // pointer to input buffer
    float *output;          // pointer to output buffer
    float *twiddle_factors; // pointer to buffer holding twiddle factors
    esp32_fft_type_t type;  // real or complex
    esp32_fft_direction_t direction; // forward or backward
    unsigned int flags;              // FFT flags
} esp32_fft_config_t;

esp32_fft_config_t *esp32_fft_init(int size,
                                   esp32_fft_type_t type,
                                   esp32_fft_direction_t direction,
                                   float *input,
                                   float *output);
void esp32_fft_destroy(esp32_fft_config_t *config);
void esp32_fft_execute(esp32_fft_config_t *config);
void esp32_fft_fft(float *input, float *output, float *twiddle_factors, int n);
void esp32_fft_ifft(float *input, float *output, float *twiddle_factors, int n);
void esp32_fft_rfft(float *x, float *y, float *twiddle_factors, int n);
void esp32_fft_irfft(float *x, float *y, float *twiddle_factors, int n);
void esp32_fft_fft_primitive(float *x,
                             float *y,
                             int n,
                             int stride,
                             float *twiddle_factors,
                             int tw_stride);
void esp32_fft_split_radix_fft(float *x,
                               float *y,
                               int n,
                               int stride,
                               float *twiddle_factors,
                               int tw_stride);
void esp32_fft_ifft_primitive(float *input,
                              float *output,
                              int n,
                              int stride,
                              float *twiddle_factors,
                              int tw_stride);
void esp32_fft_fft8(float *input, int stride_in, float *output, int stride_out);
void esp32_fft_fft4(float *input, int stride_in, float *output, int stride_out);

#ifdef __cplusplus
}
#endif

#endif // __ESP32_FFT_H__
