<template>
  <q-page class="flex flex-center">
    <q-card style="width:450px">
      <q-card-section class="bg-primary text-white">
        <div class="text-h6 text-center">Manual Control</div>
      </q-card-section>
      <q-card-section class="q-ma-lg">
        <div class="full-width row no-wrap justify-center items-center content-center">
            <q-btn
              padding="lg"
              color="primary"
              icon="keyboard_arrow_up"
              @click="move_up"
            />
        </div>

        <div class="full-width row no-wrap justify-center items-center content-center">
          <div class="col-3 self-center">
            <q-btn
            class="q-mx-auto block"
              padding="lg"
              color="primary"
              icon="keyboard_arrow_left"
              @click="move_left"
            />
          </div>
        
          <div class="col-6 self-center">
            <q-img
              src="solar-panel.png"
              :ratio="1"
            />
          </div>

          <div class="col-3 self-center">
              <q-btn
              class="q-mx-auto block"
                padding="lg"
                color="primary"
                icon="keyboard_arrow_right"
                @click="move_right"
              />
          </div>
        </div>
        
        <div class="full-width row no-wrap justify-center items-center content-center">
          <q-btn
            padding="lg"
            color="primary"
            icon="keyboard_arrow_down"
            @click="move_down"
          />
        </div>
      </q-card-section>
    </q-card>
  </q-page>
</template>

<script>
import { defineComponent } from "vue";

export default defineComponent({
  name: "PageIndex",
  mounted() {
    this.$socket.on("move_left", (data) => {
      console.log("left");
    });
  },
  methods: {
    move_up() {
      this.$socket.emit("move_up", "move_up");
    },
    move_left() {
      this.$socket.emit("move_left", "move_left");
    },
    move_right() {
      this.$socket.emit("move_right");
    },
    move_down() {
      this.$socket.emit("move_down");
    },
  },
});
</script>
