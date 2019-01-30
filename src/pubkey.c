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
#include "pubkey.h"

static int secp256k1_pubkey_y_is_odd(char *pubkey) {
    // https://git.io/fh17s
    return pubkey[64] & 1;
}

int secp256k1_pubkey_serialize(char *pubkey, size_t *size, int compress) {
    if (compress) {
        *size = 33;
        pubkey[0] = secp256k1_pubkey_y_is_odd(pubkey) ? SECP256K1_TAG_PUBKEY_ODD : SECP256K1_TAG_PUBKEY_EVEN;
    } else {
        *size = 65;
        pubkey[0] = SECP256K1_TAG_PUBKEY_UNCOMPRESSED;
    }
    return 1;
}
