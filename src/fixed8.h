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

/** Encode a fixed8 without a decimal to one with a decimal point.
 * 
 *  Out: output:  Pointer to a buffer of size strlen(input) + 1.
 * 
 *  In:  input:   Pointer to the null-teriminated input string.
 * 
 *  Returns 1 if successful.
 */
int fixed8_str_conv(char *output, char *input, char terminator);
