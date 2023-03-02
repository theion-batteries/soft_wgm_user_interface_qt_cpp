cd ..
docker build --progress=plain -t windows_qt6_image .
docker tag windows_qt6_image theionbatteries/windows_qt6_image
docker push theionbatteries/windows_qt6_image
