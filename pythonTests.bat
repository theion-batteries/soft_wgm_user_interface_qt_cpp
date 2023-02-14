start "Server Axis" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_wafer_holder_system_controller/tests/server_axis.py
start "Server Keyence" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_wafer_holder_system_controller/tests/server_keyence.py
start "WhsMotions tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_wafer_holder_system_controller/tests/run_whsMotionTests.py
start "WhsKeyence tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_wafer_holder_system_controller/tests/run_whsKeyenceTests.py
start "WhsController tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_wafer_holder_system_controller/tests/run_whsControllerTests.py




REM  start "Server Keyence" /B python tests/server_keyence.py