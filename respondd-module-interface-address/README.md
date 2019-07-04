This module adds a respondd IP address nodeinfo provider which reports the IP of a static interface.
This is useful to see an address even if no mesh network is built in.
The format is the following:

```json

{
  "nodeinfo": {
    "network": {
      "addresses": [
        "2a03:2260:3011:1160:eade:27ff:fe65:a5af"
      ]
    }
  }
}
```
