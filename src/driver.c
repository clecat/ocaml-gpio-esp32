#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/signals.h>
#include <caml/fail.h>
#include <caml/callback.h>
#include <caml/bigarray.h>
#include <esp_types.h>
#include "esp_err.h"
#include "esp_intr.h"
#include "esp_intr_alloc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/xtensa_api.h"
#include "driver/gpio.h"
#include "driver/rtc_io.h"
#include "soc/soc.h"
#include "esp_log.h"
#include "soc/gpio_periph.h"

CAMLprim value caml_gpio_get_level(value ml_gpio_nb) {
    CAMLparam1(ml_gpio_nb);
    CAMLreturn(gpio_get_level(Int_val(ml_gpio_nb)));
}
