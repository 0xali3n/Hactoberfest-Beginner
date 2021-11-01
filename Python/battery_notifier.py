import psutil
from plyer import notification
import time

battery = psutil.sensors_battery()

while(True):
    percent = battery.percent
    notification.notify(
        title="Battery Percentage",
        message=str(percent)+"% Battery remaining",
        timeout=10
    )

    time.sleep(60*60)
    continue
