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

int secp256k1_pubkey_serialize(uint8_t *pubkey, size_t *size, int compress) {
    if (compress) {
        *size = PK_COMPRESSED_LEN;
        pubkey[0] = pubkey[64] & 1 ? SECP256K1_TAG_PUBKEY_ODD : SECP256K1_TAG_PUBKEY_EVEN;
    } else {
        *size = PK_UNCOMPRESSED_LEN;
        pubkey[0] = SECP256K1_TAG_PUBKEY_UNCOMPRESSED;
    }
    return 1;
}
