
md build
pushd build
cl -Zi ../Trebuchet.cpp User32.lib
popd
