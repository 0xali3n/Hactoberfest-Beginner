import "./App.css";
import { useState, useEffect } from "react";
function App() {
  const [clockState, setClockState] = useState();

  useEffect(() => {
    setInterval(() => {
      const date = new Date();
      setClockState(date.toLocaleTimeString());
    }, 1000);
  }, []);
  return (
    <>
      <center>
        <h1>React Clock by arnavk09</h1>
        <h2>THE TIME IS:</h2>
        <div style={{ fontSize: "55px", margin: "60px" }}>{clockState}</div>
      </center>
    </>
  );
}

export default App;
