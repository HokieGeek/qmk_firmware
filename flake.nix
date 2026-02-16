{
  description = "QMK firmware development environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
        };

        qmk-db = pkgs.writeShellScriptBin "qmk-db" ''
          exec qmk compile --compiledb -kb "''${1:-gibson}" -km "''${2:-cereal}"
        '';

        qmk-flash-cereal = pkgs.writeShellScriptBin "qmk-flash-cereal" ''
          exec qmk flash -kb gibson -km cereal
        '';

        pythonEnv = pkgs.python3.withPackages (ps: with ps; [
          # from requirements.txt
          argcomplete
          colorama
          dotty-dict
          hid
          hjson
          jsonschema
          milc
          pygments
          pyserial
          pyusb
          pillow
        ]);
      in
      {
        devShells.default = pkgs.mkShell {
          name = "qmk";

          packages = with pkgs; [
            # Compilers
            gcc-arm-embedded    # ARM-based boards (RP2040, STM32, etc.)
            pkgsCross.avr.buildPackages.gcc # AVR-based boards (Pro Micro, Elite-C, etc.)
            avrdude                        # AVR flashing

            # Flashing tools
            dfu-programmer      # Atmel DFU (ATmega32U4, etc.)
            dfu-util            # STM32/RP2040 DFU
            teensy-loader-cli   # Teensy boards

            # Build tools
            gnumake
            git
            clang-tools         # clangd, clang-format

            # Python + QMK deps
            pythonEnv

            # QMK CLI
            qmk

            # udev rules helper
            libusb1

            # Helpers
            qmk-db
            qmk-flash-cereal
          ];

          shellHook = ''
            export QMK_HOME="$(pwd)"

            echo "QMK dev shell ready — QMK_HOME=$QMK_HOME"
            echo ""
            echo "  Build:  qmk compile -kb <keyboard> -km <keymap>"
            echo "  Flash:  qmk flash   -kb <keyboard> -km <keymap>"
            echo "  DB:     qmk-db [keyboard] [keymap]  (default: gibson/cereal)"
            echo ""
          '';
        };
      }
    );
}
