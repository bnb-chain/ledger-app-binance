/*******************************************************************************
*   (c) 2016 Ledger
*   (c) 2018, 2019 ZondaX GmbH
*   (c) 2019 All BNB Chain Developers
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

#include "view.h"
#include "view_templates.h"
#include "view_expl.h"
#include "common.h"

#include "glyphs.h"
#include "bagl.h"
#include "zxmacros.h"

#include <string.h>
#include <stdio.h>

#if defined(TARGET_NANOS)
// -----
static const bagl_element_t viewexpl_bagl_valuescrolling_first[] = {
        UI_FillRectangle(0, 0, 0, 128, 32, 0x000000, 0xFFFFFF),
        UI_Icon(0, 128 - 7, 0, 7, 7, BAGL_GLYPH_ICON_RIGHT),
        UI_LabelLine(1, 0, 8, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_Title),
        UI_LabelLine(1, 0, 19, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataKey),
        UI_LabelLineScrolling(2, 16, 30, 96, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataValue),
};

static const bagl_element_t viewexpl_bagl_valuescrolling[] = {
        UI_FillRectangle(0, 0, 0, 128, 32, 0x000000, 0xFFFFFF),
        UI_Icon(0, 0, 0, 7, 7, BAGL_GLYPH_ICON_LEFT),
        UI_Icon(0, 128 - 7, 0, 7, 7, BAGL_GLYPH_ICON_RIGHT),
        UI_LabelLine(1, 0, 8, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_Title),
        UI_LabelLine(1, 0, 19, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataKey),
        UI_LabelLineScrolling(2, 16, 30, 96, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataValue),
};

static const bagl_element_t viewexpl_bagl_valuescrolling_last[] = {
        UI_FillRectangle(0, 0, 0, 128, 32, 0x000000, 0xFFFFFF),
        UI_Icon(0, 0, 0, 7, 7, BAGL_GLYPH_ICON_LEFT),
        UI_Icon(0, 128 - 10, 0, 7, 7, BAGL_GLYPH_ICON_CHECK),
        UI_LabelLine(1, 0, 8, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_Title),
        UI_LabelLine(1, 0, 19, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataKey),
        UI_LabelLineScrolling(2, 16, 30, 96, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataValue),
};

static const bagl_element_t viewexpl_bagl_valuescrolling_only[] = {
        UI_FillRectangle(0, 0, 0, 128, 32, 0x000000, 0xFFFFFF),
        UI_Icon(0, 128 - 10, 0, 7, 7, BAGL_GLYPH_ICON_CHECK),
        UI_LabelLine(1, 0, 8, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_Title),
        UI_LabelLine(1, 0, 19, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataKey),
        UI_LabelLineScrolling(2, 16, 30, 96, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataValue),
};

// -----

static const bagl_element_t viewexpl_bagl_keyscrolling_first[] = {
        UI_FillRectangle(0, 0, 0, 128, 32, 0x000000, 0xFFFFFF),
        UI_Icon(0, 128 - 7, 0, 7, 7, BAGL_GLYPH_ICON_RIGHT),
        UI_LabelLine(1, 0, 8, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_Title),
        UI_LabelLine(1, 0, 30, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataValue),
        UI_LabelLineScrolling(2, 16, 19, 96, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataKey),
};

static const bagl_element_t viewexpl_bagl_keyscrolling[] = {
        UI_FillRectangle(0, 0, 0, 128, 32, 0x000000, 0xFFFFFF),
        UI_Icon(0, 0, 0, 7, 7, BAGL_GLYPH_ICON_LEFT),
        UI_Icon(0, 128 - 7, 0, 7, 7, BAGL_GLYPH_ICON_RIGHT),
        UI_LabelLine(1, 0, 8, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_Title),
        UI_LabelLine(1, 0, 30, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataValue),
        UI_LabelLineScrolling(2, 16, 19, 96, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataKey),
};

static const bagl_element_t viewexpl_bagl_keyscrolling_last[] = {
        UI_FillRectangle(0, 0, 0, 128, 32, 0x000000, 0xFFFFFF),
        UI_Icon(0, 0, 0, 7, 7, BAGL_GLYPH_ICON_LEFT),
        UI_Icon(0, 128 - 10, 0, 7, 7, BAGL_GLYPH_ICON_CHECK),
        UI_LabelLine(1, 0, 8, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_Title),
        UI_LabelLine(1, 0, 30, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataValue),
        UI_LabelLineScrolling(2, 16, 19, 96, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataKey),
};

static const bagl_element_t viewexpl_bagl_keyscrolling_only[] = {
        UI_FillRectangle(0, 0, 0, 128, 32, 0x000000, 0xFFFFFF),
        UI_Icon(0, 128 - 10, 0, 7, 7, BAGL_GLYPH_ICON_CHECK),
        UI_LabelLine(1, 0, 8, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_Title),
        UI_LabelLine(1, 0, 30, 128, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataValue),
        UI_LabelLineScrolling(2, 16, 19, 96, 11, 0xFFFFFF, 0x000000, (const char *) viewctl_DataKey),
};
// -----
#elif defined(TARGET_NANOX)

void display_next_state(bool is_upper_border);

UX_STEP_NOCB(ux_review_step, 
    pnn, 
    {
      &C_icon_eye,
      "Review",
      "transaction",
    });
UX_STEP_INIT(
    ux_init_upper_border,
    NULL,
    NULL,
    {
        display_next_state(true);
    });
UX_STEP_NOCB(
    ux_variable_display, 
    nnn,
    {
      viewctl_Title,
      viewctl_DataKey,
      viewctl_DataValue,
    });
UX_STEP_INIT(
    ux_init_lower_border,
    NULL,
    NULL,
    {
        display_next_state(false);
    });
UX_STEP_VALID(
    ux_sign_step, 
    pbb, 
    tx_accept_sign(),
    {
      &C_icon_validate_14,
      "Sign",
      "transaction",
    });
UX_STEP_VALID(
    ux_reject_step, 
    pb, 
    tx_reject(),
    {
      &C_icon_crossmark,
      "Reject",
    });
// confirm_full: confirm transaction / Amount: fullAmount / Address: fullAddress / Fees: feesAmount
UX_FLOW(ux_confirm_full_flow,
  &ux_review_step,
  &ux_init_upper_border,
  &ux_variable_display,
  &ux_init_lower_border,
  &ux_sign_step,
  &ux_reject_step
);    

volatile uint8_t current_state;

#define INSIDE_BORDERS 0
#define OUT_OF_BORDERS 1


void display_next_state(bool is_upper_border){

    if(is_upper_border){ // walking over the first border
        if(current_state == OUT_OF_BORDERS){
            current_state = INSIDE_BORDERS;
            ux_flow_next();
        }
        else{
            if(viewctl_DetailsCurrentPage > 0){
                viewctl_DetailsCurrentPage--;
                viewctl_display_page();
                ux_flow_next();
            }
            else{
                current_state = OUT_OF_BORDERS;
                ux_flow_prev();
            }
        }
    }
    else // walking over the second border
    {
        if(current_state == OUT_OF_BORDERS){
            current_state = INSIDE_BORDERS;
            viewctl_display_page();
            ux_flow_prev();
        }
        else{
            if(viewctl_DetailsCurrentPage < viewctl_DetailsPageCount - 1){
                viewctl_DetailsCurrentPage++;
                viewctl_display_page();
                ux_flow_prev();
            }
            else{
                current_state = OUT_OF_BORDERS;
                ux_flow_next();
            }
        }
    }
    
}

//////////////////////////////////////////////////////////////////////
void view_addr_next_state(bool is_upper_border);

UX_STEP_NOCB(ux_view_addr_init_step, 
    pn, 
    {
      &C_icon_eye,
      "Address list",
    });
UX_STEP_INIT(
    ux_view_addr_upper_border,
    NULL,
    NULL,
    {
        view_addr_next_state(true);
    });
UX_STEP_VALID(
    ux_view_addr_step, 
    nnn,
    view_idle(0),
    {
      viewctl_Title,
      viewctl_DataKey,
      viewctl_DataValue,
    });
UX_STEP_INIT(
    ux_view_addr_lower_border,
    NULL,
    NULL,
    {
        view_addr_next_state(false);
    });

UX_FLOW(ux_view_address_flow,
  &ux_view_addr_init_step,
  &ux_view_addr_upper_border,
  &ux_view_addr_step,
  &ux_view_addr_lower_border
);

void view_addr_next_state(bool is_upper_border){

    if(is_upper_border){ // walking over the first border
        if(current_state == OUT_OF_BORDERS){
            current_state = INSIDE_BORDERS;
            ux_flow_next();
        }
        else{
            if(viewctl_DetailsCurrentPage > 0){
                viewctl_DetailsCurrentPage--;
                viewctl_display_page();
                ux_flow_next();
            }
            else{
                current_state = OUT_OF_BORDERS;
                ux_flow_prev();
            }
        }
    }
    else // walking over the second border
    {
        if(current_state == OUT_OF_BORDERS){
            current_state = INSIDE_BORDERS;
            viewctl_display_page();
            ux_flow_prev();
        }
        else{
            if(viewctl_DetailsCurrentPage < viewctl_DetailsPageCount - 1){
                viewctl_DetailsCurrentPage++;
                viewctl_display_page();
                ux_flow_prev();
            }
            else{
                current_state = OUT_OF_BORDERS;
                ux_flow_next();
            }
        }
    }
    
}

//////////////////////////////////////////////////////////////////////

UX_STEP_NOCB(
    ux_show_addr_step, 
    nnn,
    {
      viewctl_Title,
      viewctl_DataKey,
      viewctl_DataValue,
    });
UX_STEP_VALID(
    ux_show_addr_approve_step, 
    pb, 
    show_addr_exit(),
    {
      &C_icon_validate_14,
      "Approve",
    });
UX_STEP_VALID(
    ux_show_addr_reject_step, 
    pb, 
    show_addr_exit(),
    {
      &C_icon_crossmark,
      "Reject",
    });


UX_FLOW(ux_show_address_flow,
  &ux_show_addr_step,
  &ux_show_addr_approve_step,
  &ux_show_addr_reject_step
);

//////////////////////////////////////////////////////////////////////

UX_STEP_NOCB(
    ux_get_addr_step, 
    nnn,
    {
      viewctl_Title,
      viewctl_DataKey,
      viewctl_DataValue,
    });
UX_STEP_VALID(
    ux_get_addr_approve_step, 
    pb, 
    addr_accept(),
    {
      &C_icon_validate_14,
      "Approve",
    });
UX_STEP_VALID(
    ux_get_addr_reject_step, 
    pb, 
    addr_reject(),
    {
      &C_icon_crossmark,
      "Reject",
    });


UX_FLOW(ux_get_address_flow,
  &ux_get_addr_step,
  &ux_get_addr_approve_step,
  &ux_get_addr_reject_step
);


#endif



const bagl_element_t *viewexpl_bagl_prepro(const bagl_element_t *element) {

    switch (element->component.userid) {
        case 0x01:
            UX_CALLBACK_SET_INTERVAL(2000);
            break;
        case 0x02:
            UX_CALLBACK_SET_INTERVAL(MAX(3000, 1000 + bagl_label_roundtrip_duration_ms(element, 7)));
            break;
        case 0x03:
            UX_CALLBACK_SET_INTERVAL(MAX(3000, 1000 + bagl_label_roundtrip_duration_ms(element, 7)));
            break;
    }
    return element;
}

static unsigned int viewexpl_bagl_keyscrolling_button(
        unsigned int button_mask,
        unsigned int button_mask_counter) {
    switch (button_mask) {
        // Press both left and right to switch to value scrolling
        case BUTTON_EVT_RELEASED | BUTTON_LEFT | BUTTON_RIGHT: {
            if (viewctl_scrolling_mode == KEY_SCROLLING_NO_VALUE) {
                viewctl_display_page();
            } else {
                viewctl_ehExit(0);
            }
            break;
        }

            // Press left to progress to the previous element
        case BUTTON_EVT_RELEASED | BUTTON_LEFT: {
            if (viewctl_ChunksIndex > 0) {
                submenu_left();
            } else {
                menu_left();
            }
            break;
        }

            // Hold left to progress to the previous element quickly
            // It also steps out from the value chunk page view mode
        case BUTTON_EVT_FAST | BUTTON_LEFT: {
            menu_left();
            break;
        }

            // Press right to progress to the next element
        case BUTTON_EVT_RELEASED | BUTTON_RIGHT: {
            if (viewctl_ChunksIndex < viewctl_ChunksCount - 1) {
                submenu_right();
            } else {
                menu_right();
            }
            break;
        }

            // Hold right to progress to the next element quickly
            // It also steps out from the value chunk page view mode
        case BUTTON_EVT_FAST | BUTTON_RIGHT: {
            menu_right();
            break;
        }
    }
    return 0;
}

static unsigned int viewexpl_bagl_keyscrolling_first_button(
        unsigned int button_mask,
        unsigned int button_mask_counter) {
    return viewexpl_bagl_keyscrolling_button(button_mask, button_mask_counter);
}

static unsigned int viewexpl_bagl_keyscrolling_last_button(
        unsigned int button_mask,
        unsigned int button_mask_counter) {
    return viewexpl_bagl_keyscrolling_button(button_mask, button_mask_counter);
}

static unsigned int viewexpl_bagl_keyscrolling_only_button(
        unsigned int button_mask,
        unsigned int button_mask_counter) {
    return viewexpl_bagl_keyscrolling_button(button_mask, button_mask_counter);
}

static unsigned int viewexpl_bagl_valuescrolling_button(
        unsigned int button_mask,
        unsigned int button_mask_counter) {
    return viewexpl_bagl_keyscrolling_button(button_mask, button_mask_counter);
}

static unsigned int viewexpl_bagl_valuescrolling_first_button(
        unsigned int button_mask,
        unsigned int button_mask_counter) {
    return viewexpl_bagl_valuescrolling_button(button_mask, button_mask_counter);
}

static unsigned int viewexpl_bagl_valuescrolling_last_button(
        unsigned int button_mask,
        unsigned int button_mask_counter) {
    return viewexpl_bagl_valuescrolling_button(button_mask, button_mask_counter);
}

static unsigned int viewexpl_bagl_valuescrolling_only_button(
        unsigned int button_mask,
        unsigned int button_mask_counter) {
    return viewexpl_bagl_valuescrolling_button(button_mask, button_mask_counter);
}

void viewexpl_display_ux(int page, int count) {
#if defined(TARGET_NANOS)
    if (viewctl_scrolling_mode == VALUE_SCROLLING) {
        if (page == 0) {
            UX_DISPLAY(viewexpl_bagl_valuescrolling_first, viewexpl_bagl_prepro);
            if (count - 1 <= page) {
                UX_DISPLAY(viewexpl_bagl_valuescrolling_only, viewexpl_bagl_prepro);
            }
        } else if (count - 1 <= page) {
            UX_DISPLAY(viewexpl_bagl_valuescrolling_last, viewexpl_bagl_prepro);
        } else {
            UX_DISPLAY(viewexpl_bagl_valuescrolling, viewexpl_bagl_prepro);
        }
    } else if (page == 0) {
        UX_DISPLAY(viewexpl_bagl_keyscrolling_first, viewexpl_bagl_prepro);
        if (count - 1 <= page) {
            UX_DISPLAY(viewexpl_bagl_keyscrolling_only, viewexpl_bagl_prepro);
        }
    } else if (count - 1 <= page) {
        UX_DISPLAY(viewexpl_bagl_keyscrolling_last, viewexpl_bagl_prepro);
    } else {
        UX_DISPLAY(viewexpl_bagl_keyscrolling, viewexpl_bagl_prepro);
    }
#elif defined(TARGET_NANOX)




#endif
}

void viewexpl_start(int start_page,
                    bool single_page,
                    viewctl_delegate_getData ehUpdate,
                    viewctl_delegate_ready ehReady,
                    viewctl_delegate_exit ehExit) {

    viewctl_start(start_page, single_page, ehUpdate, ehReady, ehExit, viewexpl_display_ux);

#if defined(TARGET_NANOX)
    current_state = OUT_OF_BORDERS;
#endif

}
