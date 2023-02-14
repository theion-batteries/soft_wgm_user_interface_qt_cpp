start "Server Axis" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_wafer_holder_system_controller/tests/server_axis.py
start "All tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_wafer_holder_system_controller/tests/run_tests_in_order.py
REM  start "Server Keyence" /B python tests/server_keyence.py