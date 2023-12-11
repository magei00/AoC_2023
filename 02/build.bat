
md build
pushd build
cl -Zi ../02p1.cpp User32.lib
cl -Zi ../02p2.cpp User32.lib
popd
