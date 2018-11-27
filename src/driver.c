#include <caml/mlvalues.h>
#include "driver/gpio.h"

CAMLprim value caml_gpio_get_level(value ml_gpio_nb) {
    CAMLparam1(ml_gpio_nb);
    CAMLreturn(gpio_get_level(Int_val(ml_gpio_nb)));
}
