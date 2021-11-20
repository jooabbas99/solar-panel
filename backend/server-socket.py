import eventlet
import socketio

sio = socketio.Server(cors_allowed_origins='*')
app = socketio.WSGIApp(sio)



@sio.event
def connect(sid, environ):
    print('connect ', sid)


@sio.event
def my_message(sid, data):
    print('message ', data)


@sio.event
def move_up(sid):
    print('up ')


@sio.event
def move_down(sid):
    print('down ')


@sio.event
def move_left(sid, data):
    print('left ')
    sio.emit('move_left', data, skip_sid=sid)


@sio.event
def move_right(sid):
    print('right ')


@sio.event
def current_position(sid, data):
    print('message ', data)


@sio.event
def device_mode(sid, data):
    """
        auto mode or manual mode

    """
    print('message ', data)


@sio.event
def disconnect(sid):
    print('disconnect ', sid)


if __name__ == '__main__':
    eventlet.wsgi.server(eventlet.listen(('', 8000)), app)

