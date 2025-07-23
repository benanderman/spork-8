import pcbnew
board = pcbnew.GetBoard()

spacing = 4.572 * 1000000

chip_spacing = 6 * 1000000

def place_all_components():
  first_led = board.FindFootprintByReference("D1")
  led_origin = first_led.GetPosition()
  led_orientation = first_led.GetOrientation()

  first_res = board.FindFootprintByReference("R1")
  res_origin = first_res.GetPosition()
  res_orientation = first_res.GetOrientation()

  for i in range(200):
      led = board.FindFootprintByReference("D{}".format(i + 1))
      res = board.FindFootprintByReference("R{}".format(i + 1))
      led.Value().SetVisible(False)
      res.Value().SetVisible(False)
      led.Reference().SetVisible(False)
      res.Reference().SetVisible(False)
      led.SetOrientation(led_orientation)
      res.SetOrientation(res_orientation)
      row = int(i / 10)
      col = i % 10
      led.SetPosition(pcbnew.VECTOR2I(pcbnew.wxPoint(led_origin.x + col * spacing, led_origin.y + row * spacing)))
      res.SetPosition(pcbnew.VECTOR2I(pcbnew.wxPoint(res_origin.x + col * spacing, res_origin.y + row * spacing)))


  left_cap = board.FindFootprintByReference("C1")
  left_cap_origin = left_cap.GetPosition()
  left_cap_orientation = left_cap.GetOrientation()

  right_cap = board.FindFootprintByReference("C2")
  right_cap_origin = right_cap.GetPosition()
  right_cap_orientation = right_cap.GetOrientation()

  left_chip = board.FindFootprintByReference("U1")
  left_chip_origin = left_chip.GetPosition()
  left_chip_orientation = left_chip.GetOrientation()

  right_chip = board.FindFootprintByReference("U2")
  right_chip_origin = right_chip.GetPosition()
  right_chip_orientation = right_chip.GetOrientation()

  for i in range(25):
      cap = board.FindFootprintByReference("C{}".format(i + 1))
      chip = board.FindFootprintByReference("U{}".format(i + 1))
      cap.Value().SetVisible(False)
      chip.Value().SetVisible(False)
      cap.Reference().SetVisible(False)
      chip.Reference().SetVisible(False)
      if i < 2:
        continue
      
      is_left = i % 2 == 0
      row = int(i / 2)
      if is_left:
        cap.SetOrientation(left_cap_orientation)
        chip.SetOrientation(left_chip_orientation)
        cap.SetPosition(pcbnew.VECTOR2I(pcbnew.wxPoint(left_cap_origin.x, left_cap_origin.y + row * chip_spacing)))
        chip.SetPosition(pcbnew.VECTOR2I(pcbnew.wxPoint(left_chip_origin.x, left_chip_origin.y + row * chip_spacing)))
      else:
        cap.SetOrientation(right_cap_orientation)
        chip.SetOrientation(right_chip_orientation)
        cap.SetPosition(pcbnew.VECTOR2I(pcbnew.wxPoint(right_cap_origin.x, right_cap_origin.y + row * chip_spacing)))
        chip.SetPosition(pcbnew.VECTOR2I(pcbnew.wxPoint(right_chip_origin.x, right_chip_origin.y + row * chip_spacing)))
