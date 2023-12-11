
md build
pushd build
cl -Zi ../Trebuchet.cpp User32.lib
cl -Zi ../day1p2.cpp User32.lib
popd
