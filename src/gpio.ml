module Gpio = struct
  external gpio_get_level : int -> int = "caml_gpio_get_level"
end
