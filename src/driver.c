#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <string.h>
#include "driver/gpio.h"

int mode_to_int(int mode)
{
  switch (mode) {
    case 0: return GPIO_MODE_DISABLE;
    case 1: return GPIO_MODE_INPUT;
    case 2: return GPIO_MODE_OUTPUT;
    case 3: return GPIO_MODE_OUTPUT_OD;
    case 4: return GPIO_MODE_INPUT_OUTPUT_OD;
    case 5: return GPIO_MODE_INPUT_OUTPUT;
  }
  return -1;
}

int pull_up_to_int(int pull_up)
{
  switch (pull_up) {
    case 0: return GPIO_PULLUP_DISABLE;
    case 1: return GPIO_PULLUP_ENABLE;
  }
  return -1;
}

int pull_down_to_int(int pull_down)
{
  switch (pull_down) {
    case 0: return GPIO_PULLDOWN_DISABLE;
    case 1: return GPIO_PULLDOWN_ENABLE;
  }
  return -1;
}

// esp_err_t gpio_config(const gpio_config_t *pGPIOConfig);
CAMLprim value caml_gpio_config(value ml_pin_bit_mask, value ml_mode, value ml_pull_up, value ml_pull_down, value ml_intr_type)
{
  CAMLparam5(ml_pin_bit_mask, ml_mode, ml_pull_up, ml_pull_down, ml_intr_type);
  gpio_config_t config;
  int mode = mode_to_int(Int_val(ml_mode));
  int pull_up = pull_up_to_int(Int_val(ml_pull_up));
  int pull_down = pull_down_to_int(Int_val(ml_pull_down));

  config.pin_bit_mask = 1ULL << Int_val(ml_pin_bit_mask);
  config.mode = mode;
  config.pull_up_en = pull_up;
  config.pull_down_en = pull_down;
  config.intr_type = GPIO_INTR_DISABLE;
  CAMLreturn(Val_int(gpio_config(&config)));
}

// esp_err_t gpio_reset_pin(gpio_num_t gpio_num);
CAMLprim value caml_gpio_reset_pin(value ml_gpio_num)
{
  CAMLparam1(ml_gpio_num);
  CAMLreturn(Val_int(gpio_reset_pin(Int_val(ml_gpio_num))));
}

// esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level);
CAMLprim value caml_gpio_set_level(value ml_gpio_num, value ml_level)
{
  CAMLparam2(ml_gpio_num, ml_level);
  CAMLreturn(Val_int(gpio_set_level(Int_val(ml_gpio_num), Int_val(ml_level))));
}

// int gpio_get_level(gpio_num_t gpio_num);
CAMLprim value caml_gpio_get_level(value ml_gpio_num)
{
  CAMLparam1(ml_gpio_num);
  CAMLreturn(Val_int(gpio_get_level(Int_val(ml_gpio_num))));
}

// esp_err_t gpio_set_direction(gpio_num_t gpio_num, gpio_mode_t mode);
CAMLprim value caml_gpio_set_direction(value ml_gpio_num, value ml_mode)
{
  CAMLparam2(ml_gpio_num, ml_mode);
  int mode = mode_to_int(Int_val(ml_mode));
  CAMLreturn(Val_int(gpio_set_direction(Int_val(ml_gpio_num), mode)));
}

// esp_err_t gpio_pullup_en(gpio_num_t gpio_num);
CAMLprim value caml_gpio_pullup_en(value ml_gpio_num)
{
  CAMLparam1(ml_gpio_num);
  CAMLreturn(Val_int(gpio_pullup_en(Int_val(ml_gpio_num))));
}

// esp_err_t gpio_pullup_dis(gpio_num_t gpio_num);
CAMLprim value caml_gpio_pullup_dis(value ml_gpio_num)
{
  CAMLparam1(ml_gpio_num);
  CAMLreturn(Val_int(gpio_pullup_dis(Int_val(ml_gpio_num))));
}

// esp_err_t gpio_pulldown_en(gpio_num_t gpio_num);
CAMLprim value caml_gpio_pulldown_en(value ml_gpio_num)
{
  CAMLparam1(ml_gpio_num);
  CAMLreturn(Val_int(gpio_pulldown_en(Int_val(ml_gpio_num))));
}

// esp_err_t gpio_pulldown_dis(gpio_num_t gpio_num);
CAMLprim value caml_gpio_pulldown_dis(value ml_gpio_num)
{
  CAMLparam1(ml_gpio_num);
  CAMLreturn(Val_int(gpio_pulldown_dis(Int_val(ml_gpio_num))));
}
