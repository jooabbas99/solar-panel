<template>
  <q-page class="flex flex-center">

        <q-btn
      padding="lg"
      color="primary"
      icon="keyboard_arrow_up"
      @click="move_up"
    />
        <q-btn
      padding="lg"
      color="primary"
      icon="keyboard_arrow_left"
      @click="move_left"

    />
        <q-btn
      padding="lg"
      color="primary"
      icon="keyboard_arrow_right"
      @click="move_right"

    />
        <q-btn
      padding="lg"
      color="primary"
      icon="keyboard_arrow_down"
      @click="move_down"

    />

  </q-page>
</template>

<script>
import { defineComponent } from 'vue';

export default defineComponent({
  name: 'PageIndex',
  mounted () {
    this.$socket.on("move_left",(data)=>{
      console.log(
        "left"
      );
    });
  },
    methods: {
    move_up() {
      this.$socket.emit("move_up","move_up")
    },
    move_left() {
      this.$socket.emit("move_left","move_left")
    },
    move_right() {
      this.$socket.emit("move_right")
    },
    move_down() {
      this.$socket.emit("move_down")
    },
  },
})
</script>
