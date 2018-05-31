import MQTTSNclient as m

aclient = m.Client("priyam")
aclient.registerCallback(m.Callback())
aclient.connect()

rc, topic1 = aclient.subscribe("topic1")
print "topic id for topic1 is", topic1
rc, topic2 = aclient.subscribe("topic2")
print "topic id for topic2 is", topic2
aclient.publish(topic1, "Hello i am topic 1", qos=0)
aclient.publish(topic2, "Hello i am topic 2", qos=0)
aclient.unsubscribe("topic1")
aclient.publish(topic1, "Hello i am topic 1", qos=0)
aclient.publish(topic2, "Hello i am topic 2", qos=0)
aclient.disconnect()

