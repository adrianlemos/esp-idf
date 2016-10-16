#ifndef __BT_APP_COMMON_H__
#define __BT_APP_COMMON_H__

#include <stdint.h>
#include "osi.h"
#include "bt_common_types.h"

/** Bluetooth Error Status */
/** originally defined in bluetooth.h */
typedef enum {
    BT_STATUS_SUCCESS,
    BT_STATUS_FAIL,
    BT_STATUS_NOT_READY,
    BT_STATUS_NOMEM,
    BT_STATUS_BUSY,
    BT_STATUS_DONE,
    BT_STATUS_UNSUPPORTED,
    BT_STATUS_PARAM_INVALID,
    BT_STATUS_UNHANDLED,
    BT_STATUS_AUTH_FAILURE,
    BT_STATUS_RMT_DEV_DOWN

} bt_status_t;
    
/* BT APP Events */
#define BT_EVT_APP                     (0xB000)
#define BT_EVT_APP_CONTEXT_SWITCH      (0x0001 | BT_EVT_APP)

typedef void (tBTAPP_CBACK) (uint16_t event, char *p_param);
typedef void (tBTAPP_COPY_CBACK) (uint16_t event, char *p_dest, char *p_src);

typedef struct
{
    BT_HDR               hdr;
    tBTAPP_CBACK*       p_cb;    /* context switch callback */

    /* parameters passed to callback */
    UINT16               event;   /* message event id */
    char                 p_param[0]; /* parameter area needs to be last */
} tBTAPP_CONTEXT_SWITCH_CBACK;

bt_status_t bt_app_transfer_context (tBTAPP_CBACK *p_cback, UINT16 event, char* p_params, int param_len, tBTAPP_COPY_CBACK *p_copy_cback);

void bt_app_init_ok(UNUSED_ATTR uint16_t event, UNUSED_ATTR char *p_param);

void bt_app_task_start_up(void);
#endif /* __BT_APP_COMMON_H__ */
