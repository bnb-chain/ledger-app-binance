/*******************************************************************************
*   (c) 2019 Binance
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

#include "fixed8.h"
#include <string.h>

#define DECIMAL_SCALE 8
#define ZERO_FRACTION "00000000"

int fixed8_str_conv(char *output, char *input) {
    size_t input_len = strlen(input);
    if (strrchr(output, '.')) return 0; // already converted
    char tmp[DECIMAL_SCALE + 1];
    tmp[DECIMAL_SCALE] = '\0'; // just in case
    if (input_len <= DECIMAL_SCALE) { // satoshi amount
        strcpy(tmp, input);
        output[0] = '0';
        output[1] = '.';
        strcpy(&output[2], ZERO_FRACTION);
        strcpy(&output[2 + (DECIMAL_SCALE - strlen(tmp))], tmp);
        return 1;
    }
    int input_dec_offset = input_len - DECIMAL_SCALE;
    strcpy(tmp, &input[input_dec_offset]);
    output[input_dec_offset] = '.';
    strncpy(output, input, input_len - DECIMAL_SCALE);
    strcpy(&output[input_dec_offset + 1], tmp);
    output[input_len + 1] = '\0';
    return 1;
}
