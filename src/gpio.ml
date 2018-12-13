type pin = int

type mode = Disable
          | Input
          | Output
          | OutputOd
          | InputOutputOd
          | InputOutput

type pull = Disable
          | Enable

external config : pin -> mode -> pull -> pull -> int = "caml_gpio_config"

external reset_pin : pin -> int = "caml_gpio_reset_pin"

external set_level : pin -> int -> int = "caml_gpio_set_level"
external get_level : pin -> int = "caml_gpio_get_level"

external set_direction : pin -> mode -> int = "caml_gpio_set_direction"

external pullup_en : pin -> int = "caml_gpio_pullup_en"
external pullup_dis : pin -> int = "caml_gpio_pullup_dis"
external pulldown_en : pin -> int = "caml_gpio_pulldown_en"
external pulldown_dis : pin -> int = "caml_gpio_pulldown_dis"
