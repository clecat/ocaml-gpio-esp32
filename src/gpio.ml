module Gpio = struct
  type gpio_config

  external alloc_config: unit -> gpio_config = "caml_alloc_config"
  external free_config: gpio_config -> unit = "caml_free_config"

  external config : gpio_config -> int = "caml_gpio_config"

  external reset_pin : int -> int = "caml_gpio_reset_level"

  external set_level : int -> int -> int = "caml_gpio_set_level"
  external get_level : int -> int = "caml_gpio_get_level"

  external set_intr_type : int -> int -> int = "caml_gpio_set_intr_type"
  external intr_enable : int -> int = "caml_gpio_intr_enable"
  external intr_disable : int -> int = "caml_gpio_intr_disable"

  external set_direction : int -> int -> int = "caml_gpio_set_direction"
  external set_pull_mode : int -> int -> int = "caml_gpio_set_pull_mode"

  external wakeup_enable : int -> int -> int = "caml_gpio_wakeup_enable"
  external wakeup_disable : int -> int = "caml_gpio_wakeup_disable"

  external pullup_en : int -> int = "caml_gpio_pullup_en"
  external pullup_dis : int -> int = "caml_gpio_pullup_dis"
  external pulldown_en : int -> int = "caml_gpio_pulldown_en"
  external pulldown_dis : int -> int = "caml_gpio_pulldown_dis"


  external install_isr_service : int -> int = "caml_gpio_install_isr_service"
  external uninstall_isr_service : unit -> unit = "caml_gpio_uninstall_isr_service"

  external isr_handler_remove : int -> int = "caml_gpio_isr_handler_remove"

  external set_drive_capability : int -> int -> int = "caml_gpio_set_drive_capability"
  external get_drive_capability : int -> int -> int = "caml_gpio_get_drive_capability"

  external hold_en : int -> int = "caml_gpio_hold_en"
  external hold_dis : int -> int = "caml_gpio_hold_dis"

  external iomux_in : int -> int -> int = "caml_gpio_iomux_in"
  external iomux_out : int -> int -> bool-> int = "caml_gpio_iomux_out"

end
