import QtQuick 2.0
import QtPositioning 5.6
import QtLocation 5.6

Item {
    PositionSource{
        active: true;
        onPositionChanged: { console.log(position.coordinate) }
    }

}
