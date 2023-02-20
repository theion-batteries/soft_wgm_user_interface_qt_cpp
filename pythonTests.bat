REM start whs servers
start "Server Axis" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_wafer_holder_system_controller/tests/server_axis.py
start "Server Keyence" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_wafer_holder_system_controller/tests/server_keyence.py
REM run whs tests
start "WhsMotions tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_wafer_holder_system_controller/tests/run_whsMotionTests.py
start "WhsKeyence tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_wafer_holder_system_controller/tests/run_whsKeyenceTests.py
start "WhsController tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_wafer_holder_system_controller/tests/run_whsControllerTests.py
REM start heat servers
start "server heating" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_heating_system_submodule/tests/heating_server.py
REM run whs tests
start "heatingController tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_heating_system_submodule/tests/run_heatingTests.py
REM run ph servers
start "server meteor" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/meteor_server.py
start "server trigger" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/trigger_server.py
start "server motion" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/motion_server.py
REM run ph tests
start "phMotion tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/run_phMotionTests.py
start "phtrigger tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/run_phTriggerTests.py
start "phMeteor tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/run_phMeteorSDKTests.py
start "phController tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/run_phControllerTests.py

REM run cnt servers
start "server meteor" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/meteor_server.py
start "server trigger" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/trigger_server.py
start "server motion" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/motion_server.py
REM run cnt tests
start "cntMotion tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/run_cntMotionTests.py
start "cnttrigger tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/run_cntTriggerTests.py
start "cntMeteor tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/run_cntMeteorSDKTests.py
start "cntController tests" /B python dependencies/software_wgm_v2_cpp/dependencies/soft_cooling_system_submodule_cpp/tests/run_phControllerTests.py

