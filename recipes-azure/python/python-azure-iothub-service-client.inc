DESCRIPTION = "Azure IoT Hub Service Client Library"

include azure-iot-sdk-native.inc

PR = "r0"

EXTRA_OECMAKE += "\
    -Dskip_samples:BOOL=ON \
"

do_install() {
    install -d ${D}${PYTHON_SITEPACKAGES_DIR}
    oe_libinstall -C ${B}/c/python_service_client/src -so iothub_service_client ${D}${PYTHON_SITEPACKAGES_DIR}
}

FILES_${PN} += "\
    ${PYTHON_SITEPACKAGES_DIR}/*.so \
"
