import QtQuick 2.0

Item {
    id: root;
    property int w: 3;
    property int h: 3;
    property int blockSize: 100;
    property var objects: [];
    width: w * blockSize;
    height: h * blockSize;

    Rectangle {
        anchors.fill: parent;
        color: "black";
    }

    function drawPark(id, type, x, y, free){
        if(typeof objects[id] == "undefined"){
            var component = Qt.createComponent("Park.qml");
            if (component.status === Component.Ready){
                var object = component.createObject(root, {
                    "size": blockSize,
                    "x": y * blockSize,
                    "y": x * blockSize,
                    "int_id": id
                });
                objects[id] = object;
            }
        }else{
            objects[id].x = y * blockSize;
            objects[id].y = x * blockSize;
        }
        objects[id].setFreeNumber(free);
    }

    function drawWall(id, show, x, y){
        if(typeof objects[id] == "undefined"){
            var component = Qt.createComponent("Wall.qml");
            if (component.status === Component.Ready){
                var object = component.createObject(root, {
                    "size": blockSize,
                    "x": y * blockSize,
                    "y": x * blockSize,
                    "int_id": id,
                    "show": show
                });
                objects[id] = object;
                console.log("w", x, y, show);
            }
        }else{
            objects[id].x = y * blockSize;
            objects[id].y = x * blockSize;
        }
    }

    function drawCar(id, name, x, y, isKA){
        if(typeof objects[id] == "undefined"){
            var component = Qt.createComponent("Car.qml");
            var object = component.createObject(map, {
                "size": map.blockSize,
                "x": y * map.blockSize,
                "y": x * map.blockSize,
                "int_id": id,
                "owner": name
            });
            console.log("n",name);
            if(isKA) object.setToKeyAgent();
            map.objects[id] = object;
        }else{
            objects[id].x = y * blockSize;
            objects[id].y = x * blockSize;
        }
    }
}

