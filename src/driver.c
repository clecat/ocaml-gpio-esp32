#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <string.h>
#include "driver/gpio.h"

CAMLprim value alloc_config(value unit)
{
    gpio_config_t *config;
    config = malloc(sizeof(config));
    memset(config, 0, sizeof(config));
    return (value)config;
}

CAMLprim value free_config(value ml_config)
{
    gpio_config_t *config;
    config = (gpio_config_t *) ml_config;
    free(config);
    return Val_unit;
}

// esp_err_t gpio_config(const gpio_config_t *pGPIOConfig);
CAMLprim value caml_gpio_config(value ml_config) {
    CAMLparam1(ml_config);
    gpio_config_t *config;
    config = (gpio_config_t *) ml_config;
    CAMLreturn(gpio_config(config));
}

// esp_err_t gpio_reset_pin(gpio_num_t gpio_num);
CAMLprim value caml_gpio_reset_pin(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_reset_pin(Int_val(ml_gpio_num)));
}

// esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level);
CAMLprim value caml_gpio_set_level(value ml_gpio_num, value ml_level) {
    CAMLparam2(ml_gpio_num, ml_level);
    CAMLreturn(gpio_set_level(Int_val(ml_gpio_num), Int_val(ml_level)));
}

// int gpio_get_level(gpio_num_t gpio_num);
CAMLprim value caml_gpio_get_level(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_get_level(Int_val(ml_gpio_num)));
}

// esp_err_t gpio_set_intr_type(gpio_num_t gpio_num, gpio_int_type_t intr_type);
CAMLprim value caml_gpio_set_intr_type(value ml_gpio_num, value ml_intr_type) {
    CAMLparam2(ml_gpio_num, ml_intr_type);
    CAMLreturn(gpio_set_intr_type(Int_val(ml_gpio_num), Int_val(ml_intr_type)));
}

// esp_err_t gpio_intr_enable(gpio_num_t gpio_num);
CAMLprim value caml_gpio_intr_enable(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_intr_enable(Int_val(ml_gpio_num)));
}

// esp_err_t gpio_intr_disable(gpio_num_t gpio_num);
CAMLprim value caml_gpio_intr_disable(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_intr_disable(Int_val(ml_gpio_num)));
}

// esp_err_t gpio_set_direction(gpio_num_t gpio_num, gpio_mode_t mode);
CAMLprim value caml_gpio_set_direction(value ml_gpio_num, value ml_mode) {
    CAMLparam2(ml_gpio_num, ml_mode);
    CAMLreturn(gpio_set_direction(Int_val(ml_gpio_num), Int_val(ml_mode)));
}

// esp_err_t gpio_set_pull_mode(gpio_num_t gpio_num, gpio_pull_mode_t pull);
CAMLprim value caml_gpio_set_pull_mode(value ml_gpio_num, value ml_pull) {
    CAMLparam2(ml_gpio_num, ml_pull);
    CAMLreturn(gpio_set_pull_mode(Int_val(ml_gpio_num), Int_val(ml_pull)));
}

// esp_err_t gpio_wakeup_enable(gpio_num_t gpio_num, gpio_int_type_t intr_type);
CAMLprim value caml_gpio_wakeup_enable(value ml_gpio_num, value ml_intr_type) {
    CAMLparam2(ml_gpio_num, ml_intr_type);
    CAMLreturn(gpio_wakeup_enable(Int_val(ml_gpio_num), Int_val(ml_intr_type)));
}

// esp_err_t gpio_wakeup_disable(gpio_num_t gpio_num);
CAMLprim value caml_gpio_wakeup_disable(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_wakeup_disable(Int_val(ml_gpio_num)));
}

// esp_err_t gpio_isr_register(void (*fn)(void*), void * arg, int intr_alloc_flags, gpio_isr_handle_t *handle);
// TODO

// esp_err_t gpio_pullup_en(gpio_num_t gpio_num);
CAMLprim value caml_gpio_pullup_en(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_pullup_en(Int_val(ml_gpio_num)));
}

// esp_err_t gpio_pullup_dis(gpio_num_t gpio_num);
CAMLprim value caml_gpio_pullup_dis(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_pullup_dis(Int_val(ml_gpio_num)));
}

// esp_err_t gpio_pulldown_en(gpio_num_t gpio_num);
CAMLprim value caml_gpio_pulldown_en(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_pulldown_en(Int_val(ml_gpio_num)));
}

// esp_err_t gpio_pulldown_dis(gpio_num_t gpio_num);
CAMLprim value caml_gpio_pulldown_dis(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_pulldown_dis(Int_val(ml_gpio_num)));
}

// esp_err_t gpio_install_isr_service(int intr_alloc_flags);
CAMLprim value caml_gpio_install_isr_service(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_install_isr_service(Int_val(ml_gpio_num)));
}

// void gpio_uninstall_isr_service();
CAMLprim value caml_gpio_uninstall_isr_service(value unit) {
    CAMLparam0();
    gpio_uninstall_isr_service();
    CAMLreturn(Val_unit);
}

// esp_err_t gpio_isr_handler_add(gpio_num_t gpio_num, gpio_isr_t isr_handler, void* args);
// TODO

// esp_err_t gpio_isr_handler_remove(gpio_num_t gpio_num);
CAMLprim value caml_gpio_isr_handler_remove(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_isr_handler_remove(Int_val(ml_gpio_num)));
}

// esp_err_t gpio_set_drive_capability(gpio_num_t gpio_num, gpio_drive_cap_t strength);
CAMLprim value caml_gpio_set_drive_capability(value ml_gpio_num, value ml_strength) {
    CAMLparam2(ml_gpio_num, ml_strength);
    CAMLreturn(gpio_set_drive_capability(Int_val(ml_gpio_num), Int_val(ml_strength)));
}

// esp_err_t gpio_get_drive_capability(gpio_num_t gpio_num, gpio_drive_cap_t* strength);
CAMLprim value caml_gpio_get_drive_capability(value ml_gpio_num, value ml_strength) {
    CAMLparam2(ml_gpio_num, ml_strength);
    gpio_drive_cap_t i = Int_val(ml_strength);
    CAMLreturn(gpio_get_drive_capability(Int_val(ml_gpio_num), &i));
}

// esp_err_t gpio_hold_en(gpio_num_t gpio_num);
CAMLprim value caml_gpio_hold_en(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_hold_en(Int_val(ml_gpio_num)));
}

// esp_err_t gpio_hold_dis(gpio_num_t gpio_num);
CAMLprim value caml_gpio_hold_dis(value ml_gpio_num) {
    CAMLparam1(ml_gpio_num);
    CAMLreturn(gpio_hold_dis(Int_val(ml_gpio_num)));
}

// void gpio_iomux_in(uint32_t gpio_num, uint32_t signal_idx);
CAMLprim value caml_gpio_iomux_in(value ml_gpio_num, value ml_signal_idx) {
    CAMLparam2(ml_gpio_num, ml_signal_idx);
    gpio_iomux_in(Int_val(ml_gpio_num), Int_val(ml_signal_idx));
    CAMLreturn(Val_unit);
}

// void gpio_iomux_out(uint8_t gpio_num, int func, bool oen_inv);
CAMLprim value caml_gpio_iomux_out(value ml_gpio_num, value ml_func, value ml_oen_inv) {
    CAMLparam3(ml_gpio_num, ml_func, ml_oen_inv);
    gpio_iomux_out(Int_val(ml_gpio_num), Int_val(ml_func), Bool_val(ml_oen_inv));
    CAMLreturn(Val_unit);
}
