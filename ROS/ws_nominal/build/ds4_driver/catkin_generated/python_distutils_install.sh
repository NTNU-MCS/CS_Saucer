#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/dplab/ws_nominal/src/ds4_driver"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/dplab/ws_nominal/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/dplab/ws_nominal/install/lib/python3/dist-packages:/home/dplab/ws_nominal/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/dplab/ws_nominal/build" \
    "/usr/bin/python3" \
    "/home/dplab/ws_nominal/src/ds4_driver/setup.py" \
     \
    build --build-base "/home/dplab/ws_nominal/build/ds4_driver" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/dplab/ws_nominal/install" --install-scripts="/home/dplab/ws_nominal/install/bin"
